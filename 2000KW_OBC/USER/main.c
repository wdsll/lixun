
/*
 * demo_pfc_llc.c
 * Minimal demo for GD32F303 controlling a two?stage supply:
 * - Stage 1: NCP1654 PFC (GPIO enable + ADC monitor of VBUS)
 * - Stage 2: Full-bridge/LLC driven by TIMER0 complementary PWM via NSI6602B
 *
 * Notes:
 * - Pin mapping is EXAMPLE ONLY — adjust to your PCB.
 * - Dead-time set ~500 ns at 120 MHz (DTG = 60).
 * - DIS of NSI6602B is active HIGH to force-off; we drive it LOW to enable.
 * - Simple state machine with soft-start and fault latch.
 */

#include "gd32f30x.h"
#include <stdio.h>
#include <math.h>
#include "bsp_SysTicks.h"
/* ===================== User Config ===================== */
#define SYSCLK_HZ           120000000UL

/* --- PFC / sense pins --- */
#define PFC_EN_GPIO         GPIOB
#define PFC_EN_RCU          RCU_GPIOB
#define PFC_EN_PIN          GPIO_PIN_0     /* GPIO: PB0 -> NCP1654 EN/disable (active HIGH) */

#define VBUS_ADC_CH         ADC_CHANNEL_10 /* e.g. PC0 = ADC0_IN10 */
#define VBUS_GPIO_PORT      GPIOC
#define VBUS_GPIO_PIN       GPIO_PIN_0
#define VBUS_GPIO_RCU       RCU_GPIOC

/* Divider: VBUS -> Rtop -> node(PC0) -> Rbot -> GND
   Example: Rtop=1.0M, Rbot=4.99k  => scale = (Rtop+Rbot)/Rbot ≈ 201
   Replace with your real values */
#define VBUS_SCALE          (201.0f)

/* Trip thresholds (BUS in Volts) */
#define VBUS_OK_MIN_V       (320.0f)   /* ready when >320V */
#define VBUS_OVP_V          (420.0f)   /* fault when >420V */
#define VBUS_UVP_V          (260.0f)   /* fault when <260V once enabled */

/* --- NSI6602B DIS pin (active high to disable) --- */
#define NSI_DIS_GPIO        GPIOA
#define NSI_DIS_RCU         RCU_GPIOA
#define NSI_DIS_PIN         GPIO_PIN_0

/* --- PWM output pins (example mapping) ---
   TIMER0 CH0  -> PA8   (Leg A high-side input to NSI INA_A)
   TIMER0 CH0N -> PB13  (Leg A low-side  input to NSI INB_A)
   TIMER0 CH1  -> PA9   (Leg B high-side input to NSI INA_B)
   TIMER0 CH1N -> PB14  (Leg B low-side  input to NSI INB_B)
*/
#define PWMA_H_PORT         GPIOA
#define PWMA_H_PIN          GPIO_PIN_8
#define PWMA_L_PORT         GPIOB
#define PWMA_L_PIN          GPIO_PIN_13
#define PWMB_H_PORT         GPIOA
#define PWMB_H_PIN          GPIO_PIN_9
#define PWMB_L_PORT         GPIOB
#define PWMB_L_PIN          GPIO_PIN_14

/* PWM settings */
#define PWM_FREQ_HZ         (100000U)  /* 100 kHz switching for LLC example */
#define DEADTIME_NS         (500U)     /* 500 ns dead-time */

/* Soft-start */
#define DUTY_START          (0.10f)
#define DUTY_TARGET         (0.50f)
#define DUTY_RAMP_STEP      (0.005f)     /* per control tick */
#define CTRL_TICK_HZ        (2000U)      /* 2 kHz background control loop */

/* ======================================================= */

static void clock_config(void);
static void gpio_config(void);
static void adc_config(void);
static void timer0_pwm_fullbridge_init(uint32_t pwm_hz, uint32_t deadtime_ns, float duty);
static uint16_t adc_read_vbus_raw(void);
static float    vbus_read_volts(void);
static void     delay_ms(uint32_t ms);

/* Simple state machine */
typedef enum {
    SYS_OFF = 0,
    SYS_WAIT_VBUS_READY,
    SYS_SOFTSTART,
    SYS_RUN,
    SYS_FAULT
} sys_state_t;

static volatile sys_state_t g_state = SYS_OFF;
static volatile float g_duty = DUTY_START;

int main(void)
{
    clock_config();
    gpio_config();
    adc_config();

    /* Ensure everything off */
    gpio_bit_reset(PFC_EN_GPIO, PFC_EN_PIN);    /* PFC disabled */
    gpio_bit_reset(NSI_DIS_GPIO, NSI_DIS_PIN);  /* default LOW enables driver; we will keep disabled initially */
    gpio_bit_set(NSI_DIS_GPIO, NSI_DIS_PIN);    /* keep driver disabled during bring-up */

    /* Set up PWM but keep outputs idle until RUN */
    timer0_pwm_fullbridge_init(PWM_FREQ_HZ, DEADTIME_NS, DUTY_START);

    /* Start control tick using SysTick */
    systick_delay_config();

    g_state = SYS_WAIT_VBUS_READY;

    while (1) {
        float vbus = vbus_read_volts();

        switch (g_state) {
        case SYS_WAIT_VBUS_READY:
            /* Enable PFC and wait until bus rises > VBUS_OK_MIN_V */
            gpio_bit_set(PFC_EN_GPIO, PFC_EN_PIN);
            if (vbus > VBUS_OK_MIN_V) {
                /* Enable gate driver and proceed to soft-start */
                gpio_bit_reset(NSI_DIS_GPIO, NSI_DIS_PIN); /* LOW = enable */
                g_state = SYS_SOFTSTART;
            }
            break;

        case SYS_SOFTSTART:
            /* Ramp duty to target */
            if (g_duty < DUTY_TARGET) {
                g_duty += DUTY_RAMP_STEP;
                if (g_duty > DUTY_TARGET) g_duty = DUTY_TARGET;
                /* Update compare on both channels */
                uint32_t timer_clk = SYSCLK_HZ;
                uint32_t period = (timer_clk / PWM_FREQ_HZ) - 1U;
                uint32_t pulse = (uint32_t)((period + 1U) * g_duty);
                timer_channel_output_pulse_value_config(TIMER0, TIMER_CH_0, pulse);
                timer_channel_output_pulse_value_config(TIMER0, TIMER_CH_1, pulse);
            } else {
                g_state = SYS_RUN;
            }
            /* fallthrough */
        case SYS_RUN:
            /* Runtime protections */
            if (vbus > VBUS_OVP_V || vbus < VBUS_UVP_V) {
                g_state = SYS_FAULT;
            }
            break;

        case SYS_FAULT:
            /* Latch off */
            gpio_bit_reset(PFC_EN_GPIO, PFC_EN_PIN);   /* disable PFC */
            gpio_bit_set(NSI_DIS_GPIO, NSI_DIS_PIN);   /* disable driver */
            /* stay here; user can reset MCU to clear */
            break;

        default:
            g_state = SYS_OFF;
            break;
        }

        delay_ms(1);
    }
}

/* ----- Clock: 120 MHz using HSE+PLL (adjust to your board) ----- */
static void clock_config(void)
{
		ErrStatus ok;
		rcu_deinit();
    /* Enable HSE and wait */
    rcu_osci_on(RCU_HXTAL);
    if (ok != rcu_osci_stab_wait(RCU_HXTAL))
		{
			while(1);
		}
		fmc_wscnt_set(3);
		rcu_ahb_clock_config(RCU_AHB_CKSYS_DIV1);
    rcu_apb2_clock_config(RCU_APB2_CKAHB_DIV1);
    rcu_apb1_clock_config(RCU_APB1_CKAHB_DIV2);
#if defined(RCU_PLLPRESSEL_HXTAL)
    rcu_pllpresel_config(RCU_PLLPRESSEL_HXTAL);   /* 预选 HXTAL */
#else
    rcu_pllpresel_config(RCU_PLLPRESRC_HXTAL);    /* 旧库的宏名 */
#endif
		
		rcu_predv0_config(RCU_PREDV0_DIV2);
		rcu_pll_config(RCU_PLLSRC_HXTAL_IRC48M, RCU_PLL_MUL30);
		rcu_osci_on(RCU_PLL_CK);
		 while (rcu_flag_get(RCU_FLAG_PLLSTB) == RESET) { /* 等待 PLL 锁定 */ }
		 rcu_system_clock_source_config(RCU_CKSYSSRC_PLL);
    while (rcu_system_clock_source_get() != RCU_SCSS_PLL) { }

    SystemCoreClock = SYSCLK_HZ;
}

/* ----- GPIO for PFC_EN, NSI_DIS, ADC pin, PWM pins ----- */
static void gpio_config(void)
{
    /* Clocks */
    rcu_periph_clock_enable(PFC_EN_RCU);
    rcu_periph_clock_enable(NSI_DIS_RCU);
    rcu_periph_clock_enable(VBUS_GPIO_RCU);
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);

    /* PFC_EN: push-pull output, default LOW */
    gpio_init(PFC_EN_GPIO, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, PFC_EN_PIN);
    gpio_bit_reset(PFC_EN_GPIO, PFC_EN_PIN);

    /* NSI_DIS: push-pull output, default HIGH (disabled) */
    gpio_init(NSI_DIS_GPIO, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, NSI_DIS_PIN);
    gpio_bit_set(NSI_DIS_GPIO, NSI_DIS_PIN);

    /* ADC pin PC0 analog */
    gpio_init(VBUS_GPIO_PORT, GPIO_MODE_AIN, GPIO_OSPEED_50MHZ, VBUS_GPIO_PIN);

    /* PWM pins alternate-function push-pull */
    gpio_init(PWMA_H_PORT, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, PWMA_H_PIN);
    gpio_init(PWMA_L_PORT, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, PWMA_L_PIN);
    gpio_init(PWMB_H_PORT, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, PWMB_H_PIN);
    gpio_init(PWMB_L_PORT, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, PWMB_L_PIN);
}

/* ----- ADC single channel for VBUS divider (ADC0) ----- */
static void adc_config(void)
{
    rcu_periph_clock_enable(RCU_ADC0);

    /* ADC clock: APB2/6  (assumes APB2=120 MHz -> ADC=20 MHz) */
    rcu_adc_clock_config(RCU_CKADC_CKAPB2_DIV6);

    adc_deinit(ADC0);
    adc_mode_config(ADC_MODE_FREE);
    adc_data_alignment_config(ADC0, ADC_DATAALIGN_RIGHT);
    adc_channel_length_config(ADC0, ADC_REGULAR_CHANNEL, 1);
    adc_external_trigger_source_config(ADC0, ADC_REGULAR_CHANNEL, ADC0_1_2_EXTTRIG_REGULAR_NONE);
    adc_external_trigger_config(ADC0, ADC_REGULAR_CHANNEL, ENABLE);

    adc_regular_channel_config(ADC0, 0, VBUS_ADC_CH, ADC_SAMPLETIME_239POINT5);

    adc_enable(ADC0);
    delay_ms(1);
    adc_calibration_enable(ADC0);
}

static uint16_t adc_read_vbus_raw(void)
{
    adc_software_trigger_enable(ADC0, ADC_REGULAR_CHANNEL);
    while (!adc_flag_get(ADC0, ADC_FLAG_EOC));
    adc_flag_clear(ADC0, ADC_FLAG_EOC);
    return adc_regular_data_read(ADC0);
}

static float vbus_read_volts(void)
{
    uint16_t raw = adc_read_vbus_raw();
    /* 12-bit ADC reference 3.3V (adjust if different) */
    float v_sense = (3.3f * (float)raw) / 4095.0f;
    return v_sense * VBUS_SCALE;
}

/* ----- TIMER0 full-bridge complementary PWM ----- */
static void timer0_pwm_fullbridge_init(uint32_t pwm_hz, uint32_t deadtime_ns, float duty)
{
    rcu_periph_clock_enable(RCU_TIMER0);

    uint32_t timer_clk = SYSCLK_HZ;
    uint16_t prescaler = 0;
    uint32_t period = (timer_clk / pwm_hz) - 1U;

    timer_parameter_struct base = {0};
    timer_deinit(TIMER0);

    base.prescaler         = prescaler;
    base.alignedmode       = TIMER_COUNTER_EDGE;   /* or TIMER_COUNTER_CENTER_DOWN for center-aligned */
    base.counterdirection  = TIMER_COUNTER_UP;
    base.period            = period;
    base.clockdivision     = TIMER_CKDIV_DIV1;
    base.repetitioncounter = 0;
    timer_init(TIMER0, &base);

    /* Deadtime ticks = deadtime_ns / (1e9 / timer_clk) */ //硬件时间限制
    uint32_t dt_ticks = (uint32_t)((deadtime_ns * (uint64_t)timer_clk) / 1000000000ULL);
    if (dt_ticks > 255) dt_ticks = 255;

    timer_break_parameter_struct bk = {0};
    bk.runoffstate      = TIMER_ROS_STATE_ENABLE;
    bk.ideloffstate     = TIMER_IOS_STATE_DISABLE;
    bk.deadtime         = (uint8_t)dt_ticks;
    bk.breakpolarity    = TIMER_BREAK_POLARITY_LOW;
    bk.outputautostate  = TIMER_OUTAUTO_ENABLE;
    bk.protectmode      = TIMER_CCHP_PROT_OFF;
    bk.breakstate       = TIMER_BREAK_DISABLE;
    timer_break_config(TIMER0, &bk);

    /* Channel common config */
    timer_oc_parameter_struct oc = {0};
    oc.ocpolarity       = TIMER_OC_POLARITY_HIGH;
    oc.outputstate      = TIMER_CCX_ENABLE;
    oc.ocnpolarity      = TIMER_OCN_POLARITY_HIGH;
    oc.outputnstate     = TIMER_CCXN_ENABLE;
    oc.ocidlestate      = TIMER_OC_IDLE_STATE_LOW;
    oc.ocnidlestate     = TIMER_OCN_IDLE_STATE_LOW;

    timer_channel_output_config(TIMER0, TIMER_CH_0, &oc);
    timer_channel_output_config(TIMER0, TIMER_CH_1, &oc);

    timer_channel_output_mode_config(TIMER0, TIMER_CH_0, TIMER_OC_MODE_PWM1);
    timer_channel_output_mode_config(TIMER0, TIMER_CH_1, TIMER_OC_MODE_PWM1);
    timer_channel_output_shadow_config(TIMER0, TIMER_CH_0, TIMER_OC_SHADOW_DISABLE);
    timer_channel_output_shadow_config(TIMER0, TIMER_CH_1, TIMER_OC_SHADOW_DISABLE);

    uint32_t pulse = (uint32_t)((period + 1U) * duty);
    timer_channel_output_pulse_value_config(TIMER0, TIMER_CH_0, pulse);
    timer_channel_output_pulse_value_config(TIMER0, TIMER_CH_1, pulse);

    /* For full-bridge, create 180° phase shift between legs by using channel polarity/inversion if needed
       (Here we keep both same duty; transformer/LLC determines current via resonance.
       Advanced: use TIMER DMA/update events to shift phase dynamically.) */

    timer_primary_output_config(TIMER0, ENABLE);
    timer_enable(TIMER0);
}


/* crude delay (ms) */
static void delay_ms(uint32_t ms)
{
    uint32_t cycles = (SYSCLK_HZ/4000U) * ms; /* approx */
    for (volatile uint32_t i = 0; i < cycles; ++i) __NOP();
}


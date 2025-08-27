################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./User/LlcAdc.obj" \
"./User/LlcCan.obj" \
"./User/LlcDS1338.obj" \
"./User/LlcEEPROM.obj" \
"./User/LlcErr.obj" \
"./User/LlcFlow.obj" \
"./User/LlcGpio.obj" \
"./User/LlcIIC.obj" \
"./User/LlcInit.obj" \
"./User/LlcLed.obj" \
"./User/LlcLin.obj" \
"./User/LlcLoop.obj" \
"./User/LlcMain.obj" \
"./User/LlcPwm.obj" \
"./User/LlcSci.obj" \
"./User/LlcSys.obj" \
"./User/LlcTimer.obj" \
"./User/LlcUSB.obj" \
"./User/eeprom_24xx.obj" \
"./User/i2c_gpio.obj" \
"./library/DSP2803x_Adc.obj" \
"./library/DSP2803x_CodeStartBranch.obj" \
"./library/DSP2803x_CpuTimers.obj" \
"./library/DSP2803x_DefaultIsr.obj" \
"./library/DSP2803x_ECan.obj" \
"./library/DSP2803x_EPwm.obj" \
"./library/DSP2803x_GlobalVariableDefs.obj" \
"./library/DSP2803x_MemCopy.obj" \
"./library/DSP2803x_PieCtrl.obj" \
"./library/DSP2803x_PieVect.obj" \
"./library/DSP2803x_Sci.obj" \
"./library/DSP2803x_SysCtrl.obj" \
"./library/DSP2803x_TempSensorConv.obj" \
"./library/DSP2803x_usDelay.obj" \
"../F28035v1.cmd" \
"../library/DSP2803x_Headers_nonBIOS.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include User/subdir_vars.mk
-include library/subdir_vars.mk
-include subdir_rules.mk
-include User/subdir_rules.mk
-include library/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
111111.out \

EXE_OUTPUTS__QUOTED += \
"111111.out" \


# All Target
all: 111111.out

# Tool invocations
111111.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/cl2000" -v28 -ml -mt -g --diag_warning=225 --display_error_number -z --stack_size=0x300 -m"111111.map" --warn_sections -i"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/lib" -i"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/include" --reread_libs --display_error_number --xml_link_info="111111_linkInfo.xml" --rom_model -o "111111.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "User\LlcAdc.obj" "User\LlcCan.obj" "User\LlcDS1338.obj" "User\LlcEEPROM.obj" "User\LlcErr.obj" "User\LlcFlow.obj" "User\LlcGpio.obj" "User\LlcIIC.obj" "User\LlcInit.obj" "User\LlcLed.obj" "User\LlcLin.obj" "User\LlcLoop.obj" "User\LlcMain.obj" "User\LlcPwm.obj" "User\LlcSci.obj" "User\LlcSys.obj" "User\LlcTimer.obj" "User\LlcUSB.obj" "User\eeprom_24xx.obj" "User\i2c_gpio.obj" "library\DSP2803x_Adc.obj" "library\DSP2803x_CodeStartBranch.obj" "library\DSP2803x_CpuTimers.obj" "library\DSP2803x_DefaultIsr.obj" "library\DSP2803x_ECan.obj" "library\DSP2803x_EPwm.obj" "library\DSP2803x_GlobalVariableDefs.obj" "library\DSP2803x_MemCopy.obj" "library\DSP2803x_PieCtrl.obj" "library\DSP2803x_PieVect.obj" "library\DSP2803x_Sci.obj" "library\DSP2803x_SysCtrl.obj" "library\DSP2803x_TempSensorConv.obj" "library\DSP2803x_usDelay.obj" 
	-$(RM) "User\LlcAdc.d" "User\LlcCan.d" "User\LlcDS1338.d" "User\LlcEEPROM.d" "User\LlcErr.d" "User\LlcFlow.d" "User\LlcGpio.d" "User\LlcIIC.d" "User\LlcInit.d" "User\LlcLed.d" "User\LlcLin.d" "User\LlcLoop.d" "User\LlcMain.d" "User\LlcPwm.d" "User\LlcSci.d" "User\LlcSys.d" "User\LlcTimer.d" "User\LlcUSB.d" "User\eeprom_24xx.d" "User\i2c_gpio.d" "library\DSP2803x_Adc.d" "library\DSP2803x_CpuTimers.d" "library\DSP2803x_DefaultIsr.d" "library\DSP2803x_ECan.d" "library\DSP2803x_EPwm.d" "library\DSP2803x_GlobalVariableDefs.d" "library\DSP2803x_MemCopy.d" "library\DSP2803x_PieCtrl.d" "library\DSP2803x_PieVect.d" "library\DSP2803x_Sci.d" "library\DSP2803x_SysCtrl.d" "library\DSP2803x_TempSensorConv.d" 
	-$(RM) "library\DSP2803x_CodeStartBranch.d" "library\DSP2803x_usDelay.d" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-@echo 'Create flash image: Intel-HEX'
	-"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-c2000_20.2.1.LTS/bin/hex2000" -i "111111.out" -o "111111.hex" -order MS -romwidth 16
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets


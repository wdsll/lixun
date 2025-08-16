################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/retarget.c \
../src/sbc_fs23.c \
../src/adc_handler.c

OBJS += \
./src/main.o \
./src/retarget.o \
./src/sbc_fs23.o \
./src/adc_handler.o

C_DEPS += \
./src/main.d \
./src/retarget.d \
./src/sbc_fs23.d \
./src/adc_handler.d


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



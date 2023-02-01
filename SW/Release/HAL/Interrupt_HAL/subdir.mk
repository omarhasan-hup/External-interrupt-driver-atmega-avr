################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Interrupt_HAL/interrupt.c 

OBJS += \
./HAL/Interrupt_HAL/interrupt.o 

C_DEPS += \
./HAL/Interrupt_HAL/interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Interrupt_HAL/%.o: ../HAL/Interrupt_HAL/%.c HAL/Interrupt_HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\eclipse work space\External_Interrupt_Driver\HAL\Interrupt_HAL" -I"D:\eclipse work space\External_Interrupt_Driver\MCAL" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



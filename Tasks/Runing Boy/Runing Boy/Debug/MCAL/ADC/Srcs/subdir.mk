################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC/Srcs/ADC.c \
../MCAL/ADC/Srcs/ADC_IRQ.c 

OBJS += \
./MCAL/ADC/Srcs/ADC.o \
./MCAL/ADC/Srcs/ADC_IRQ.o 

C_DEPS += \
./MCAL/ADC/Srcs/ADC.d \
./MCAL/ADC/Srcs/ADC_IRQ.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/ADC/Srcs/%.o: ../MCAL/ADC/Srcs/%.c MCAL/ADC/Srcs/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



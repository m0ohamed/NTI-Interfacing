################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXTI/Srcs/EXTI.c \
../MCAL/EXTI/Srcs/EXTI_IRQs.c 

OBJS += \
./MCAL/EXTI/Srcs/EXTI.o \
./MCAL/EXTI/Srcs/EXTI_IRQs.o 

C_DEPS += \
./MCAL/EXTI/Srcs/EXTI.d \
./MCAL/EXTI/Srcs/EXTI_IRQs.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXTI/Srcs/%.o: ../MCAL/EXTI/Srcs/%.c MCAL/EXTI/Srcs/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



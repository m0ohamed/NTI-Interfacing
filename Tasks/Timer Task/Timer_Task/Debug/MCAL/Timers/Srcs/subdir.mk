################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timers/Srcs/Timer.c \
../MCAL/Timers/Srcs/Timer_IRQ.c 

OBJS += \
./MCAL/Timers/Srcs/Timer.o \
./MCAL/Timers/Srcs/Timer_IRQ.o 

C_DEPS += \
./MCAL/Timers/Srcs/Timer.d \
./MCAL/Timers/Srcs/Timer_IRQ.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timers/Srcs/%.o: ../MCAL/Timers/Srcs/%.c MCAL/Timers/Srcs/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



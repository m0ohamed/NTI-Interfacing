################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Port/Srcs/Port.c 

OBJS += \
./MCAL/Port/Srcs/Port.o 

C_DEPS += \
./MCAL/Port/Srcs/Port.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Port/Srcs/%.o: ../MCAL/Port/Srcs/%.c MCAL/Port/Srcs/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../Keypad.c \
../LCD.c \
../TimerModule.c \
../interrupt.c \
../main.c 

OBJS += \
./ADC.o \
./Keypad.o \
./LCD.o \
./TimerModule.o \
./interrupt.o \
./main.o 

C_DEPS += \
./ADC.d \
./Keypad.d \
./LCD.d \
./TimerModule.d \
./interrupt.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



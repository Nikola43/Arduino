################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/usr/share/arduino/hardware/arduino/cores/arduino/avr-libc/malloc.c \
/usr/share/arduino/hardware/arduino/cores/arduino/avr-libc/realloc.c 

C_DEPS += \
./arduino/malloc.c.d \
./arduino/realloc.c.d 

AR_OBJ += \
./arduino/malloc.c.o \
./arduino/realloc.c.o 


# Each subdirectory must supply rules for building sources it contributes
arduino/malloc.c.o: /usr/share/arduino/hardware/arduino/cores/arduino/avr-libc/malloc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/usr/share/arduino/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-gcc" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=atmega32u4 -DF_CPU=16000000L -DARDUINO=1 105+dfsg2-2 -DARDUINO_ -DARDUINO_ARCH_ARDUINO  "-I/libsam" "-I/CMSIS/CMSIS/Include/" "-I/CMSIS/Device/ATMEL/"   -I"/usr/share/arduino/hardware/arduino/cores/arduino" -I"/usr/share/arduino/hardware/arduino/variants/leonardo" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/realloc.c.o: /usr/share/arduino/hardware/arduino/cores/arduino/avr-libc/realloc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/usr/share/arduino/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-gcc" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -Dprintf=iprintf -mcpu=atmega32u4 -DF_CPU=16000000L -DARDUINO=1 105+dfsg2-2 -DARDUINO_ -DARDUINO_ARCH_ARDUINO  "-I/libsam" "-I/CMSIS/CMSIS/Include/" "-I/CMSIS/Device/ATMEL/"   -I"/usr/share/arduino/hardware/arduino/cores/arduino" -I"/usr/share/arduino/hardware/arduino/variants/leonardo" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '



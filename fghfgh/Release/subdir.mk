################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../fghfgh.cpp 

CPP_DEPS += \
./fghfgh.cpp.d 

LINK_OBJ += \
./fghfgh.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
fghfgh.cpp.o: ../fghfgh.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/usr/share/arduino/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -c -g -Os -ffunction-sections -fdata-sections -nostdlib --param max-inline-insns-single=500 -fno-rtti -fno-exceptions -Dprintf=iprintf -mcpu=atmega32u4 -DF_CPU=16000000L -DARDUINO=1 105+dfsg2-2 -DARDUINO_ -DARDUINO_ARCH_ARDUINO  "-I/libsam" "-I/CMSIS/CMSIS/Include/" "-I/CMSIS/Device/ATMEL/"   -I"/usr/share/arduino/hardware/arduino/cores/arduino" -I"/usr/share/arduino/hardware/arduino/variants/leonardo" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/usr/share/arduino/hardware/arduino/cores/robot/CDC.cpp \
/usr/share/arduino/hardware/arduino/cores/robot/HID.cpp \
/usr/share/arduino/hardware/arduino/cores/robot/HardwareSerial.cpp \
/usr/share/arduino/hardware/arduino/cores/robot/IPAddress.cpp \
/usr/share/arduino/hardware/arduino/cores/robot/Print.cpp \
/usr/share/arduino/hardware/arduino/cores/robot/Stream.cpp \
/usr/share/arduino/hardware/arduino/cores/robot/Tone.cpp \
/usr/share/arduino/hardware/arduino/cores/robot/USBCore.cpp \
/usr/share/arduino/hardware/arduino/cores/robot/WMath.cpp \
/usr/share/arduino/hardware/arduino/cores/robot/WString.cpp \
/usr/share/arduino/hardware/arduino/cores/robot/main.cpp \
/usr/share/arduino/hardware/arduino/cores/robot/new.cpp 

C_SRCS += \
/usr/share/arduino/hardware/arduino/cores/robot/WInterrupts.c \
/usr/share/arduino/hardware/arduino/cores/robot/wiring.c \
/usr/share/arduino/hardware/arduino/cores/robot/wiring_analog.c \
/usr/share/arduino/hardware/arduino/cores/robot/wiring_digital.c \
/usr/share/arduino/hardware/arduino/cores/robot/wiring_pulse.c \
/usr/share/arduino/hardware/arduino/cores/robot/wiring_shift.c 

C_DEPS += \
./arduino/WInterrupts.c.d \
./arduino/wiring.c.d \
./arduino/wiring_analog.c.d \
./arduino/wiring_digital.c.d \
./arduino/wiring_pulse.c.d \
./arduino/wiring_shift.c.d 

AR_OBJ += \
./arduino/CDC.cpp.o \
./arduino/HID.cpp.o \
./arduino/HardwareSerial.cpp.o \
./arduino/IPAddress.cpp.o \
./arduino/Print.cpp.o \
./arduino/Stream.cpp.o \
./arduino/Tone.cpp.o \
./arduino/USBCore.cpp.o \
./arduino/WInterrupts.c.o \
./arduino/WMath.cpp.o \
./arduino/WString.cpp.o \
./arduino/main.cpp.o \
./arduino/new.cpp.o \
./arduino/wiring.c.o \
./arduino/wiring_analog.c.o \
./arduino/wiring_digital.c.o \
./arduino/wiring_pulse.c.o \
./arduino/wiring_shift.c.o 

CPP_DEPS += \
./arduino/CDC.cpp.d \
./arduino/HID.cpp.d \
./arduino/HardwareSerial.cpp.d \
./arduino/IPAddress.cpp.d \
./arduino/Print.cpp.d \
./arduino/Stream.cpp.d \
./arduino/Tone.cpp.d \
./arduino/USBCore.cpp.d \
./arduino/WMath.cpp.d \
./arduino/WString.cpp.d \
./arduino/main.cpp.d \
./arduino/new.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
arduino/CDC.cpp.o: /usr/share/arduino/hardware/arduino/cores/robot/CDC.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/HID.cpp.o: /usr/share/arduino/hardware/arduino/cores/robot/HID.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/HardwareSerial.cpp.o: /usr/share/arduino/hardware/arduino/cores/robot/HardwareSerial.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/IPAddress.cpp.o: /usr/share/arduino/hardware/arduino/cores/robot/IPAddress.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/Print.cpp.o: /usr/share/arduino/hardware/arduino/cores/robot/Print.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/Stream.cpp.o: /usr/share/arduino/hardware/arduino/cores/robot/Stream.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/Tone.cpp.o: /usr/share/arduino/hardware/arduino/cores/robot/Tone.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/USBCore.cpp.o: /usr/share/arduino/hardware/arduino/cores/robot/USBCore.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/WInterrupts.c.o: /usr/share/arduino/hardware/arduino/cores/robot/WInterrupts.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/WMath.cpp.o: /usr/share/arduino/hardware/arduino/cores/robot/WMath.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/WString.cpp.o: /usr/share/arduino/hardware/arduino/cores/robot/WString.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/main.cpp.o: /usr/share/arduino/hardware/arduino/cores/robot/main.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/new.cpp.o: /usr/share/arduino/hardware/arduino/cores/robot/new.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 -x c++ "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring.c.o: /usr/share/arduino/hardware/arduino/cores/robot/wiring.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_analog.c.o: /usr/share/arduino/hardware/arduino/cores/robot/wiring_analog.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_digital.c.o: /usr/share/arduino/hardware/arduino/cores/robot/wiring_digital.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_pulse.c.o: /usr/share/arduino/hardware/arduino/cores/robot/wiring_pulse.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_shift.c.o: /usr/share/arduino/hardware/arduino/cores/robot/wiring_shift.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	-I"/usr/share/arduino/hardware/arduino/cores" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -D__IN_ECLIPSE__=1 "$<"  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '



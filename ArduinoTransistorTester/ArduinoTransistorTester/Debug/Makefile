################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../ADC.c \
../adjust.c \
../ADS7843.c \
../cap.c \
../display.c \
../extras.c \
../HD44780_Par4.c \
../ILI9341_SPI.c \
../inductor.c \
../IR.c \
../main.c \
../pause.c \
../probes.c \
../resistor.c \
../semi.c \
../ST7565R_SPI.c \
../user.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
ADC.o \
adjust.o \
ADS7843.o \
cap.o \
display.o \
extras.o \
HD44780_Par4.o \
ILI9341_SPI.o \
inductor.o \
IR.o \
main.o \
pause.o \
probes.o \
resistor.o \
semi.o \
ST7565R_SPI.o \
user.o

OBJS_AS_ARGS +=  \
ADC.o \
adjust.o \
ADS7843.o \
cap.o \
display.o \
extras.o \
HD44780_Par4.o \
ILI9341_SPI.o \
inductor.o \
IR.o \
main.o \
pause.o \
probes.o \
resistor.o \
semi.o \
ST7565R_SPI.o \
user.o

C_DEPS +=  \
ADC.d \
adjust.d \
ADS7843.d \
cap.d \
display.d \
extras.d \
HD44780_Par4.d \
ILI9341_SPI.d \
inductor.d \
IR.d \
main.d \
pause.d \
probes.d \
resistor.d \
semi.d \
ST7565R_SPI.d \
user.d

C_DEPS_AS_ARGS +=  \
ADC.d \
adjust.d \
ADS7843.d \
cap.d \
display.d \
extras.d \
HD44780_Par4.d \
ILI9341_SPI.d \
inductor.d \
IR.d \
main.d \
pause.d \
probes.d \
resistor.d \
semi.d \
ST7565R_SPI.d \
user.d

OUTPUT_FILE_PATH +=ArduinoTransistorTester.elf

OUTPUT_FILE_PATH_AS_ARGS +=ArduinoTransistorTester.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler



































./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.9.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=16000000  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\gcc\dev\atmega328" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.9.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="ArduinoTransistorTester.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega328 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.90\gcc\dev\atmega328"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "ArduinoTransistorTester.elf" "ArduinoTransistorTester.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "ArduinoTransistorTester.elf" "ArduinoTransistorTester.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "ArduinoTransistorTester.elf" > "ArduinoTransistorTester.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "ArduinoTransistorTester.elf" "ArduinoTransistorTester.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "ArduinoTransistorTester.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "ArduinoTransistorTester.elf" "ArduinoTransistorTester.a" "ArduinoTransistorTester.hex" "ArduinoTransistorTester.lss" "ArduinoTransistorTester.eep" "ArduinoTransistorTester.map" "ArduinoTransistorTester.srec" "ArduinoTransistorTester.usersignatures"
	
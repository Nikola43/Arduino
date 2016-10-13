################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/avr-libc/subdir.mk
-include arduino/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/paulo/MEGA/Arduino/sketchbook/fghfgh/Release/arduino.ar \

ELF += \
fghfgh.elf \

EEP += \
fghfgh.eep \

FLASH_IMAGE += \
fghfgh.bin \


# All Target
all: fghfgh

# Tool invocations
fghfgh: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/usr/share/arduino/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-size" -A "/home/paulo/MEGA/Arduino/sketchbook/fghfgh/Release/fghfgh.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/paulo/MEGA/Arduino/sketchbook/fghfgh/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/usr/share/arduino/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-ar" rcs "/home/paulo/MEGA/Arduino/sketchbook/fghfgh/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

fghfgh.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/usr/share/arduino/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-g++" -Os -Wl,--gc-sections -mcpu=atmega32u4 "-T/usr/share/arduino/hardware/arduino/variants/leonardo/" "-Wl,-Map,/home/paulo/MEGA/Arduino/sketchbook/fghfgh/Release/fghfgh.map" -o "/home/paulo/MEGA/Arduino/sketchbook/fghfgh/Release/fghfgh.elf" "-L/home/paulo/MEGA/Arduino/sketchbook/fghfgh/Release" -lm -lgcc -mthumb -Wl,--cref -Wl,--check-sections -Wl,--gc-sections -Wl,--entry=Reset_Handler -Wl,--unresolved-symbols=report-all -Wl,--warn-common -Wl,--warn-section-align -Wl,--warn-unresolved-symbols -Wl,--start-group "/home/paulo/MEGA/Arduino/sketchbook/fghfgh/Release/arduino/syscalls_sam3.c.o"   $(LINK_OBJ) $(AR)  "/usr/share/arduino/hardware/arduino/variants/leonardo/" "/home/paulo/MEGA/Arduino/sketchbook/fghfgh/Release/arduino.ar" -Wl,--end-group
	@echo 'Finished building: $@'
	@echo ' '

fghfgh.eep: $(ELF)
	@echo 'Create eeprom image'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

fghfgh.bin: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/usr/share/arduino/hardware/tools/g++_arm_none_eabi/bin/arm-none-eabi-objcopy" -O binary "/home/paulo/MEGA/Arduino/sketchbook/fghfgh/Release/fghfgh.elf" "/home/paulo/MEGA/Arduino/sketchbook/fghfgh/Release/fghfgh.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_DEPS)$(AR)$(FLASH_IMAGE)$(EEP)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ELF)$(ASM_DEPS)$(CC_DEPS)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(C_UPPER_DEPS)$(SIZEDUMMY) fghfgh
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

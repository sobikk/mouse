################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/Peripheral_drivers/subdir.mk
-include Drivers/Modul\ drivers/subdir.mk
-include Drivers/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Mouse_v3.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Mouse_v3.list \

OBJCOPY_BIN += \
Mouse_v3.bin \


# All Target
all: Mouse_v3.elf secondary-outputs

# Tool invocations
Mouse_v3.elf: $(OBJS) $(USER_OBJS) /Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/STM32F042C4TX_FLASH.ld
	arm-none-eabi-gcc -o "Mouse_v3.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/STM32F042C4TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Mouse_v3.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Mouse_v3.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Mouse_v3.list"
	@echo 'Finished building: $@'
	@echo ' '

Mouse_v3.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Mouse_v3.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

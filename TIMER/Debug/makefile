################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/TIMER/WATCHDOG/subdir.mk
-include MCAL/TIMER/TIMER1/subdir.mk
-include MCAL/TIMER/TIMER0/subdir.mk
-include MCAL/TIMER/ICU_HW/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EINT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LM35/subdir.mk
-include HAL/LCD/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
TIMER.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: TIMER.elf secondary-outputs

# Tool invocations
TIMER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TIMER.map -mmcu=atmega32 -o "TIMER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TIMER.lss: TIMER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TIMER.elf  >"TIMER.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TIMER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TIMER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TIMER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

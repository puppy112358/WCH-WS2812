################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include cmake-build-debug-riscv-none-embed-gcc/CMakeFiles/ina_iic.elf.dir/User/subdir.mk
-include cmake-build-debug-riscv-none-embed-gcc/CMakeFiles/ina_iic.elf.dir/Startup/subdir.mk
-include cmake-build-debug-riscv-none-embed-gcc/CMakeFiles/ina_iic.elf.dir/Peripheral/src/subdir.mk
-include cmake-build-debug-riscv-none-embed-gcc/CMakeFiles/ina_iic.elf.dir/Debug/subdir.mk
-include cmake-build-debug-riscv-none-embed-gcc/CMakeFiles/ina_iic.elf.dir/Core/subdir.mk
-include cmake-build-debug-riscv-none-embed-gcc/CMakeFiles/3.28.1/CompilerIdCXX/subdir.mk
-include cmake-build-debug-riscv-none-embed-gcc/CMakeFiles/3.28.1/CompilerIdC/subdir.mk
-include cmake-build-debug-riscv-none-embed-gcc/subdir.mk
-include User/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
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
SECONDARY_FLASH += \
I2C_EEPROM.hex \

SECONDARY_LIST += \
I2C_EEPROM.lst \

SECONDARY_SIZE += \
I2C_EEPROM.siz \


# 所有目标
all: I2C_EEPROM.elf secondary-outputs

# 工具调用
I2C_EEPROM.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"I2C_EEPROM.map" --specs=nano.specs --specs=nosys.specs -o "I2C_EEPROM.elf" $(OBJS) $(USER_OBJS) $(LIBS) -lprintf
	@	@
I2C_EEPROM.hex: I2C_EEPROM.elf
	@	riscv-none-embed-objcopy -O ihex "I2C_EEPROM.elf"  "I2C_EEPROM.hex"
	@	@
I2C_EEPROM.lst: I2C_EEPROM.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "I2C_EEPROM.elf" > "I2C_EEPROM.lst"
	@	@
I2C_EEPROM.siz: I2C_EEPROM.elf
	@	riscv-none-embed-size --format=berkeley "I2C_EEPROM.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) I2C_EEPROM.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets

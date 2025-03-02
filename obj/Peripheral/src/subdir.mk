################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_adc.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_bkp.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_can.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_crc.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_dbgmcu.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_dma.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_exti.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_flash.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_gpio.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_i2c.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_iwdg.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_lptim.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_misc.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_opa.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_pwr.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_rcc.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_rtc.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_spi.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_tim.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_usart.c \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_wwdg.c 

OBJS += \
./Peripheral/src/ch32l103_adc.o \
./Peripheral/src/ch32l103_bkp.o \
./Peripheral/src/ch32l103_can.o \
./Peripheral/src/ch32l103_crc.o \
./Peripheral/src/ch32l103_dbgmcu.o \
./Peripheral/src/ch32l103_dma.o \
./Peripheral/src/ch32l103_exti.o \
./Peripheral/src/ch32l103_flash.o \
./Peripheral/src/ch32l103_gpio.o \
./Peripheral/src/ch32l103_i2c.o \
./Peripheral/src/ch32l103_iwdg.o \
./Peripheral/src/ch32l103_lptim.o \
./Peripheral/src/ch32l103_misc.o \
./Peripheral/src/ch32l103_opa.o \
./Peripheral/src/ch32l103_pwr.o \
./Peripheral/src/ch32l103_rcc.o \
./Peripheral/src/ch32l103_rtc.o \
./Peripheral/src/ch32l103_spi.o \
./Peripheral/src/ch32l103_tim.o \
./Peripheral/src/ch32l103_usart.o \
./Peripheral/src/ch32l103_wwdg.o 

C_DEPS += \
./Peripheral/src/ch32l103_adc.d \
./Peripheral/src/ch32l103_bkp.d \
./Peripheral/src/ch32l103_can.d \
./Peripheral/src/ch32l103_crc.d \
./Peripheral/src/ch32l103_dbgmcu.d \
./Peripheral/src/ch32l103_dma.d \
./Peripheral/src/ch32l103_exti.d \
./Peripheral/src/ch32l103_flash.d \
./Peripheral/src/ch32l103_gpio.d \
./Peripheral/src/ch32l103_i2c.d \
./Peripheral/src/ch32l103_iwdg.d \
./Peripheral/src/ch32l103_lptim.d \
./Peripheral/src/ch32l103_misc.d \
./Peripheral/src/ch32l103_opa.d \
./Peripheral/src/ch32l103_pwr.d \
./Peripheral/src/ch32l103_rcc.d \
./Peripheral/src/ch32l103_rtc.d \
./Peripheral/src/ch32l103_spi.d \
./Peripheral/src/ch32l103_tim.d \
./Peripheral/src/ch32l103_usart.d \
./Peripheral/src/ch32l103_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/ch32l103_adc.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_bkp.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_bkp.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_can.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_can.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_crc.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_crc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_dbgmcu.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_dbgmcu.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_dma.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_dma.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_exti.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_exti.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_flash.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_gpio.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_i2c.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_i2c.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_iwdg.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_iwdg.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_lptim.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_lptim.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_misc.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_misc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_opa.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_opa.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_pwr.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_pwr.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_rcc.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_rcc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_rtc.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_rtc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_spi.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_spi.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_tim.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_tim.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_usart.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_usart.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32l103_wwdg.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Peripheral/src/ch32l103_wwdg.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Debug" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Core" -I"E:\wch\CH32L103EVT\EVT\EXAM\I2C\I2C_EEPROM\User" -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@


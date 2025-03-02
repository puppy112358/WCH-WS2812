################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32l103_it.c \
../User/ina226.c \
../User/main.c \
../User/system_ch32l103.c 

OBJS += \
./User/ch32l103_it.o \
./User/ina226.o \
./User/main.o \
./User/system_ch32l103.o 

C_DEPS += \
./User/ch32l103_it.d \
./User/ina226.d \
./User/main.d \
./User/system_ch32l103.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\SRC\Debug" -I"E:\SRC\Core" -I"E:\wch\ina_iic\User" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@


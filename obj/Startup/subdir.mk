################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
E:/wch/CH32L103EVT/EVT/EXAM/SRC/Startup/startup_ch32l103.S 

OBJS += \
./Startup/startup_ch32l103.o 

S_UPPER_DEPS += \
./Startup/startup_ch32l103.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_ch32l103.o: E:/wch/CH32L103EVT/EVT/EXAM/SRC/Startup/startup_ch32l103.S
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -x assembler-with-cpp -I"E:\wch\CH32L103EVT\EVT\EXAM\SRC\Startup" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@


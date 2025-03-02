################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cmake-build-debug/CMakeFiles/3.28.1/CompilerIdC/CMakeCCompilerId.c 

OBJS += \
./cmake-build-debug/CMakeFiles/3.28.1/CompilerIdC/CMakeCCompilerId.o 

C_DEPS += \
./cmake-build-debug/CMakeFiles/3.28.1/CompilerIdC/CMakeCCompilerId.d 


# Each subdirectory must supply rules for building sources it contributes
cmake-build-debug/CMakeFiles/3.28.1/CompilerIdC/%.o: ../cmake-build-debug/CMakeFiles/3.28.1/CompilerIdC/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\SRC\Debug" -I"E:\SRC\Core" -I"E:\wch\ina_iic\User" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@


################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projekty/STM32/test2/testSD2/Src/system_stm32l4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32l4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32l4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32l4xx.o: D:/Projekty/STM32/test2/testSD2/Src/system_stm32l4xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L452xx -I"D:/Projekty/STM32/test2/testSD2/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"D:/Projekty/STM32/test2/testSD2/Middlewares/Third_Party/FatFs/src" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Include" -I"D:/Projekty/STM32/test2/testSD2/Inc"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projekty/STM32/test2/testSD2/Src/bsp_driver_sd.c \
D:/Projekty/STM32/test2/testSD2/Src/fatfs.c \
D:/Projekty/STM32/test2/testSD2/Src/main.c \
D:/Projekty/STM32/test2/testSD2/Src/sd_diskio.c \
D:/Projekty/STM32/test2/testSD2/Src/stm32l4xx_hal_msp.c \
D:/Projekty/STM32/test2/testSD2/Src/stm32l4xx_it.c 

OBJS += \
./Application/User/bsp_driver_sd.o \
./Application/User/fatfs.o \
./Application/User/main.o \
./Application/User/sd_diskio.o \
./Application/User/stm32l4xx_hal_msp.o \
./Application/User/stm32l4xx_it.o 

C_DEPS += \
./Application/User/bsp_driver_sd.d \
./Application/User/fatfs.d \
./Application/User/main.d \
./Application/User/sd_diskio.d \
./Application/User/stm32l4xx_hal_msp.d \
./Application/User/stm32l4xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/bsp_driver_sd.o: D:/Projekty/STM32/test2/testSD2/Src/bsp_driver_sd.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L452xx -I"D:/Projekty/STM32/test2/testSD2/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"D:/Projekty/STM32/test2/testSD2/Middlewares/Third_Party/FatFs/src" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Include" -I"D:/Projekty/STM32/test2/testSD2/Inc"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/fatfs.o: D:/Projekty/STM32/test2/testSD2/Src/fatfs.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L452xx -I"D:/Projekty/STM32/test2/testSD2/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"D:/Projekty/STM32/test2/testSD2/Middlewares/Third_Party/FatFs/src" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Include" -I"D:/Projekty/STM32/test2/testSD2/Inc"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/main.o: D:/Projekty/STM32/test2/testSD2/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L452xx -I"D:/Projekty/STM32/test2/testSD2/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"D:/Projekty/STM32/test2/testSD2/Middlewares/Third_Party/FatFs/src" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Include" -I"D:/Projekty/STM32/test2/testSD2/Inc"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/sd_diskio.o: D:/Projekty/STM32/test2/testSD2/Src/sd_diskio.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L452xx -I"D:/Projekty/STM32/test2/testSD2/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"D:/Projekty/STM32/test2/testSD2/Middlewares/Third_Party/FatFs/src" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Include" -I"D:/Projekty/STM32/test2/testSD2/Inc"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32l4xx_hal_msp.o: D:/Projekty/STM32/test2/testSD2/Src/stm32l4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L452xx -I"D:/Projekty/STM32/test2/testSD2/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"D:/Projekty/STM32/test2/testSD2/Middlewares/Third_Party/FatFs/src" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Include" -I"D:/Projekty/STM32/test2/testSD2/Inc"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32l4xx_it.o: D:/Projekty/STM32/test2/testSD2/Src/stm32l4xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32L452xx -I"D:/Projekty/STM32/test2/testSD2/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc" -I"D:/Projekty/STM32/test2/testSD2/Drivers/STM32L4xx_HAL_Driver/Inc/Legacy" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Device/ST/STM32L4xx/Include" -I"D:/Projekty/STM32/test2/testSD2/Middlewares/Third_Party/FatFs/src" -I"D:/Projekty/STM32/test2/testSD2/Drivers/CMSIS/Include" -I"D:/Projekty/STM32/test2/testSD2/Inc"  -O3 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



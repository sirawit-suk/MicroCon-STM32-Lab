################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32-AM2320-master/am2320.c 

OBJS += \
./Drivers/STM32-AM2320-master/am2320.o 

C_DEPS += \
./Drivers/STM32-AM2320-master/am2320.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32-AM2320-master/%.o: ../Drivers/STM32-AM2320-master/%.c Drivers/STM32-AM2320-master/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/ASUS/STM32CubeIDE/MAD_Lab_1.7.0/Lab08/Drivers/ILI9341" -I"C:/Users/ASUS/STM32CubeIDE/MAD_Lab_1.7.0/Lab08/Drivers/STM32-AM2320-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


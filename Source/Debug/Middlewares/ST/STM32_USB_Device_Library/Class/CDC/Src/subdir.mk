################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c 

OBJS += \
./Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.o 

C_DEPS += \
./Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/%.o: ../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F105xC -I"C:/Users/CCM/Desktop/Priv/Isys/test/Inc" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



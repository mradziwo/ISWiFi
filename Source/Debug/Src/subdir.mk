################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC.c \
../Src/HysteresisController.c \
../Src/config.c \
../Src/database.c \
../Src/filter.c \
../Src/freertos.c \
../Src/led.c \
../Src/main.c \
../Src/relays.c \
../Src/stm32f1xx_hal_msp.c \
../Src/stm32f1xx_it.c \
../Src/system_stm32f1xx.c \
../Src/usb_device.c \
../Src/usbd_cdc_if.c \
../Src/usbd_conf.c \
../Src/usbd_desc.c \
../Src/vcp.c 

OBJS += \
./Src/ADC.o \
./Src/HysteresisController.o \
./Src/config.o \
./Src/database.o \
./Src/filter.o \
./Src/freertos.o \
./Src/led.o \
./Src/main.o \
./Src/relays.o \
./Src/stm32f1xx_hal_msp.o \
./Src/stm32f1xx_it.o \
./Src/system_stm32f1xx.o \
./Src/usb_device.o \
./Src/usbd_cdc_if.o \
./Src/usbd_conf.o \
./Src/usbd_desc.o \
./Src/vcp.o 

C_DEPS += \
./Src/ADC.d \
./Src/HysteresisController.d \
./Src/config.d \
./Src/database.d \
./Src/filter.d \
./Src/freertos.d \
./Src/led.d \
./Src/main.d \
./Src/relays.d \
./Src/stm32f1xx_hal_msp.d \
./Src/stm32f1xx_it.d \
./Src/system_stm32f1xx.d \
./Src/usb_device.d \
./Src/usbd_cdc_if.d \
./Src/usbd_conf.d \
./Src/usbd_desc.d \
./Src/vcp.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F105xC -I"C:/Users/CCM/Desktop/Priv/Isys/test/Inc" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/CCM/Desktop/Priv/Isys/test/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Peripheral_drivers/ADC_driver.c \
../Drivers/Peripheral_drivers/EXTI_driver.c \
../Drivers/Peripheral_drivers/GPIO_driver.c \
../Drivers/Peripheral_drivers/NVIC_driver.c \
../Drivers/Peripheral_drivers/RCC_driver.c \
../Drivers/Peripheral_drivers/SPI_driver.c \
../Drivers/Peripheral_drivers/SYSCFG_driver.c \
../Drivers/Peripheral_drivers/TIM16_driver.c \
../Drivers/Peripheral_drivers/TIM17_driver.c \
../Drivers/Peripheral_drivers/USB_driver.c 

OBJS += \
./Drivers/Peripheral_drivers/ADC_driver.o \
./Drivers/Peripheral_drivers/EXTI_driver.o \
./Drivers/Peripheral_drivers/GPIO_driver.o \
./Drivers/Peripheral_drivers/NVIC_driver.o \
./Drivers/Peripheral_drivers/RCC_driver.o \
./Drivers/Peripheral_drivers/SPI_driver.o \
./Drivers/Peripheral_drivers/SYSCFG_driver.o \
./Drivers/Peripheral_drivers/TIM16_driver.o \
./Drivers/Peripheral_drivers/TIM17_driver.o \
./Drivers/Peripheral_drivers/USB_driver.o 

C_DEPS += \
./Drivers/Peripheral_drivers/ADC_driver.d \
./Drivers/Peripheral_drivers/EXTI_driver.d \
./Drivers/Peripheral_drivers/GPIO_driver.d \
./Drivers/Peripheral_drivers/NVIC_driver.d \
./Drivers/Peripheral_drivers/RCC_driver.d \
./Drivers/Peripheral_drivers/SPI_driver.d \
./Drivers/Peripheral_drivers/SYSCFG_driver.d \
./Drivers/Peripheral_drivers/TIM16_driver.d \
./Drivers/Peripheral_drivers/TIM17_driver.d \
./Drivers/Peripheral_drivers/USB_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Peripheral_drivers/ADC_driver.o: ../Drivers/Peripheral_drivers/ADC_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/ADC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/EXTI_driver.o: ../Drivers/Peripheral_drivers/EXTI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/GPIO_driver.o: ../Drivers/Peripheral_drivers/GPIO_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/NVIC_driver.o: ../Drivers/Peripheral_drivers/NVIC_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/NVIC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/RCC_driver.o: ../Drivers/Peripheral_drivers/RCC_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/SPI_driver.o: ../Drivers/Peripheral_drivers/SPI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/SPI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/SYSCFG_driver.o: ../Drivers/Peripheral_drivers/SYSCFG_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/SYSCFG_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/TIM16_driver.o: ../Drivers/Peripheral_drivers/TIM16_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/TIM16_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/TIM17_driver.o: ../Drivers/Peripheral_drivers/TIM17_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/TIM17_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/USB_driver.o: ../Drivers/Peripheral_drivers/USB_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/USB_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


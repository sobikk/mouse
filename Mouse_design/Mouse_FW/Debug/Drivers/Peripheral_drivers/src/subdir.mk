################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Peripheral_drivers/src/ADC_driver.c \
../Drivers/Peripheral_drivers/src/EXTI_driver.c \
../Drivers/Peripheral_drivers/src/GPIO_driver.c \
../Drivers/Peripheral_drivers/src/NVIC_driver.c \
../Drivers/Peripheral_drivers/src/RCC_driver.c \
../Drivers/Peripheral_drivers/src/SPI_driver.c \
../Drivers/Peripheral_drivers/src/SYSCFG_driver.c \
../Drivers/Peripheral_drivers/src/TIM16_driver.c \
../Drivers/Peripheral_drivers/src/TIM17_driver.c 

OBJS += \
./Drivers/Peripheral_drivers/src/ADC_driver.o \
./Drivers/Peripheral_drivers/src/EXTI_driver.o \
./Drivers/Peripheral_drivers/src/GPIO_driver.o \
./Drivers/Peripheral_drivers/src/NVIC_driver.o \
./Drivers/Peripheral_drivers/src/RCC_driver.o \
./Drivers/Peripheral_drivers/src/SPI_driver.o \
./Drivers/Peripheral_drivers/src/SYSCFG_driver.o \
./Drivers/Peripheral_drivers/src/TIM16_driver.o \
./Drivers/Peripheral_drivers/src/TIM17_driver.o 

C_DEPS += \
./Drivers/Peripheral_drivers/src/ADC_driver.d \
./Drivers/Peripheral_drivers/src/EXTI_driver.d \
./Drivers/Peripheral_drivers/src/GPIO_driver.d \
./Drivers/Peripheral_drivers/src/NVIC_driver.d \
./Drivers/Peripheral_drivers/src/RCC_driver.d \
./Drivers/Peripheral_drivers/src/SPI_driver.d \
./Drivers/Peripheral_drivers/src/SYSCFG_driver.d \
./Drivers/Peripheral_drivers/src/TIM16_driver.d \
./Drivers/Peripheral_drivers/src/TIM17_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Peripheral_drivers/src/ADC_driver.o: ../Drivers/Peripheral_drivers/src/ADC_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Device_drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/src/ADC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/src/EXTI_driver.o: ../Drivers/Peripheral_drivers/src/EXTI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Device_drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/src/EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/src/GPIO_driver.o: ../Drivers/Peripheral_drivers/src/GPIO_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Device_drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/src/GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/src/NVIC_driver.o: ../Drivers/Peripheral_drivers/src/NVIC_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Device_drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/src/NVIC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/src/RCC_driver.o: ../Drivers/Peripheral_drivers/src/RCC_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Device_drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/src/RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/src/SPI_driver.o: ../Drivers/Peripheral_drivers/src/SPI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Device_drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/src/SPI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/src/SYSCFG_driver.o: ../Drivers/Peripheral_drivers/src/SYSCFG_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Device_drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/src/SYSCFG_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/src/TIM16_driver.o: ../Drivers/Peripheral_drivers/src/TIM16_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Device_drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/src/TIM16_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral_drivers/src/TIM17_driver.o: ../Drivers/Peripheral_drivers/src/TIM17_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Device_drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral_drivers/src/TIM17_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


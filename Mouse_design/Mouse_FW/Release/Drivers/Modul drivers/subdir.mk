################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Modul\ drivers/AD8556_driver.c \
../Drivers/Modul\ drivers/BUTTON_driver.c \
../Drivers/Modul\ drivers/INAMP_driver.c \
../Drivers/Modul\ drivers/LED_driver.c \
../Drivers/Modul\ drivers/OMS_driver.c 

OBJS += \
./Drivers/Modul\ drivers/AD8556_driver.o \
./Drivers/Modul\ drivers/BUTTON_driver.o \
./Drivers/Modul\ drivers/INAMP_driver.o \
./Drivers/Modul\ drivers/LED_driver.o \
./Drivers/Modul\ drivers/OMS_driver.o 

C_DEPS += \
./Drivers/Modul\ drivers/AD8556_driver.d \
./Drivers/Modul\ drivers/BUTTON_driver.d \
./Drivers/Modul\ drivers/INAMP_driver.d \
./Drivers/Modul\ drivers/LED_driver.d \
./Drivers/Modul\ drivers/OMS_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Modul\ drivers/AD8556_driver.o: ../Drivers/Modul\ drivers/AD8556_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Modul drivers/AD8556_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Modul\ drivers/BUTTON_driver.o: ../Drivers/Modul\ drivers/BUTTON_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Modul drivers/BUTTON_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Modul\ drivers/INAMP_driver.o: ../Drivers/Modul\ drivers/INAMP_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Modul drivers/INAMP_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Modul\ drivers/LED_driver.o: ../Drivers/Modul\ drivers/LED_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Modul drivers/LED_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Modul\ drivers/OMS_driver.o: ../Drivers/Modul\ drivers/OMS_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -DSTM32 -DSTM32F0 -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Modul drivers/OMS_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


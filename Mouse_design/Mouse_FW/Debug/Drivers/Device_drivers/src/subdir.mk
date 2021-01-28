################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Device_drivers/src/DEV_driver.c 

OBJS += \
./Drivers/Device_drivers/src/DEV_driver.o 

C_DEPS += \
./Drivers/Device_drivers/src/DEV_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Device_drivers/src/DEV_driver.o: ../Drivers/Device_drivers/src/DEV_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F042C4Tx -c -I../Inc -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Device_drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers/inc" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Device_drivers/src/DEV_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f042c4tx.s 

OBJS += \
./Startup/startup_stm32f042c4tx.o 

S_DEPS += \
./Startup/startup_stm32f042c4tx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f042c4tx.o: ../Startup/startup_stm32f042c4tx.s
	arm-none-eabi-gcc -mcpu=cortex-m0 -g3 -c -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Modul drivers" -I"/Users/sobik/Project_Xexe/Myš/FW_Design/Mys_01/Mouse_v3/Drivers/Peripheral_drivers" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f042c4tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"


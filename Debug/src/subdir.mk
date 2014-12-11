################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BAMBrisk.cpp \
../src/Test.cpp \
../src/brisk.cpp 

OBJS += \
./src/BAMBrisk.o \
./src/Test.o \
./src/brisk.o 

CPP_DEPS += \
./src/BAMBrisk.d \
./src/Test.d \
./src/brisk.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/lucabaroffio/Documents/workspace/BAMBrisk/src/thirdparty/agast/include" -I"/Users/lucabaroffio/Documents/workspace/BAMBrisk/include" -I/usr/local/include -I/opt/local/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



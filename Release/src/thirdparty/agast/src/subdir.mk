################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/thirdparty/agast/src/AstDetector.cc \
../src/thirdparty/agast/src/agast5_8.cc \
../src/thirdparty/agast/src/agast5_8_nms.cc \
../src/thirdparty/agast/src/agast7_12d.cc \
../src/thirdparty/agast/src/agast7_12d_nms.cc \
../src/thirdparty/agast/src/agast7_12s.cc \
../src/thirdparty/agast/src/agast7_12s_nms.cc \
../src/thirdparty/agast/src/nonMaximumSuppression.cc \
../src/thirdparty/agast/src/oast9_16.cc \
../src/thirdparty/agast/src/oast9_16_nms.cc 

OBJS += \
./src/thirdparty/agast/src/AstDetector.o \
./src/thirdparty/agast/src/agast5_8.o \
./src/thirdparty/agast/src/agast5_8_nms.o \
./src/thirdparty/agast/src/agast7_12d.o \
./src/thirdparty/agast/src/agast7_12d_nms.o \
./src/thirdparty/agast/src/agast7_12s.o \
./src/thirdparty/agast/src/agast7_12s_nms.o \
./src/thirdparty/agast/src/nonMaximumSuppression.o \
./src/thirdparty/agast/src/oast9_16.o \
./src/thirdparty/agast/src/oast9_16_nms.o 

CC_DEPS += \
./src/thirdparty/agast/src/AstDetector.d \
./src/thirdparty/agast/src/agast5_8.d \
./src/thirdparty/agast/src/agast5_8_nms.d \
./src/thirdparty/agast/src/agast7_12d.d \
./src/thirdparty/agast/src/agast7_12d_nms.d \
./src/thirdparty/agast/src/agast7_12s.d \
./src/thirdparty/agast/src/agast7_12s_nms.d \
./src/thirdparty/agast/src/nonMaximumSuppression.d \
./src/thirdparty/agast/src/oast9_16.d \
./src/thirdparty/agast/src/oast9_16_nms.d 


# Each subdirectory must supply rules for building sources it contributes
src/thirdparty/agast/src/%.o: ../src/thirdparty/agast/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/lucabaroffio/Documents/workspace/BAMBrisk/src/thirdparty/agast/include" -I"/Users/lucabaroffio/Documents/workspace/BAMBrisk/include" -I/usr/local/include -I/opt/local/include -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



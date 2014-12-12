################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ChapterThree/RuntimeException.cpp \
../ChapterThree/SetOfStacks.cpp \
../ChapterThree/SetOfStacks_test.cpp \
../ChapterThree/StackWithMin.cpp \
../ChapterThree/StackWithMin_test.cpp \
../ChapterThree/ThreeStacksInOne.cpp \
../ChapterThree/ThreeStacksInOne_test.cpp 

OBJS += \
./ChapterThree/RuntimeException.o \
./ChapterThree/SetOfStacks.o \
./ChapterThree/SetOfStacks_test.o \
./ChapterThree/StackWithMin.o \
./ChapterThree/StackWithMin_test.o \
./ChapterThree/ThreeStacksInOne.o \
./ChapterThree/ThreeStacksInOne_test.o 

CPP_DEPS += \
./ChapterThree/RuntimeException.d \
./ChapterThree/SetOfStacks.d \
./ChapterThree/SetOfStacks_test.d \
./ChapterThree/StackWithMin.d \
./ChapterThree/StackWithMin_test.d \
./ChapterThree/ThreeStacksInOne.d \
./ChapterThree/ThreeStacksInOne_test.d 


# Each subdirectory must supply rules for building sources it contributes
ChapterThree/%.o: ../ChapterThree/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



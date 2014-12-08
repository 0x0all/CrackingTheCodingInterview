################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ChapterFour/BinaryTree_test.cpp \
../ChapterFour/GraphNode_test.cpp \
../ChapterFour/Graph_test.cpp \
../ChapterFour/TreeNode_test.cpp 

OBJS += \
./ChapterFour/BinaryTree_test.o \
./ChapterFour/GraphNode_test.o \
./ChapterFour/Graph_test.o \
./ChapterFour/TreeNode_test.o 

CPP_DEPS += \
./ChapterFour/BinaryTree_test.d \
./ChapterFour/GraphNode_test.d \
./ChapterFour/Graph_test.d \
./ChapterFour/TreeNode_test.d 


# Each subdirectory must supply rules for building sources it contributes
ChapterFour/%.o: ../ChapterFour/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



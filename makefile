CH_ONE_OBJ := StringUtil.o StringUtil_test.o
CH_TWO_OBJ := LinkedListNode_test.o RuntimeExceptionOne.o
CH_THREE_OBJ := MyQueue_test.o RuntimeExceptionTwo.o SetOfStacks.o SetOfStacks_test.o StackWithMin.o StackWithMin_test.o ThreeStacksInOne_test.o ThreeStacksInOne.o
CH_FOUR_OBJ := BinaryTree_test.o GraphNode_test.o Graph_test.o TreeNode_test.o
CH_FIVE_OBJ := BitManipulator_test.o StrangeArray.o StrangeArray_test.o
CH_SEVEN_OBJ := CallHandle.o CallHandle_test.o Employee.o Employee_test.o
OBJ = $(CH_ONE_OBJ) $(CH_TWO_OBJ) $(CH_THREE_OBJ) $(CH_FOUR_OBJ) $(CH_FIVE_OBJ)\
$(CH_SEVEN_OBJ)
CC := g++
DEBUG := -g3
CFLAGS := -O0 -Wall -c -std=c++11 $(DEGUB)
LIBS := -lgtest -lgtest_main -lpthread

CrackingTheCodingInterview: $(OBJ)
	$(CC) -o CrackingTheCodingInterview $(OBJ) $(LIBS)

#CH_ONE_OBJ
StringUtil_test.o: StringUtil.o
	$(CC) $(CFLAGS) ChapterOne/StringUtil_test.cpp

StringUtil.o: ChapterOne/StringUtil.h ChapterOne/StringUtil.cpp
	$(CC) $(CFLAGS) ChapterOne/StringUtil.cpp

#CH_TWO_OBJ
LinkedListNode_test.o: RuntimeExceptionOne.o
	$(CC) $(CFLAGS) ChapterTwo/LinkedListNode_test.cpp

RuntimeExceptionOne.o: ChapterTwo/RuntimeException.h ChapterTwo/RuntimeException.cpp
	$(CC) $(CFLAGS) ChapterTwo/RuntimeException.cpp -o RuntimeExceptionOne.o

#CH_THREE_OBJ
MyQueue_test.o: ChapterThree/MyQueue_test.cpp
	$(CC) $(CFLAGS) ChapterThree/MyQueue_test.cpp

RuntimeExceptionTwo.o: ChapterThree/RuntimeException.h ChapterThree/RuntimeException.cpp
	$(CC) $(CFLAGS) ChapterThree/RuntimeException.cpp -o RuntimeExceptionTwo.o

SetOfStacks_test.o: SetOfStacks.o
	$(CC) $(CFLAGS) ChapterThree/SetOfStacks_test.cpp

SetOfStacks.o: ChapterThree/SetOfStacks.h ChapterThree/SetOfStacks.cpp ChapterThree/RuntimeException.h
	$(CC) $(CFLAGS) ChapterThree/SetOfStacks.cpp

StackWithMin_test.o: StackWithMin.o
	$(CC) $(CFLAGS) ChapterThree/StackWithMin_test.cpp

StackWithMin.o: ChapterThree/StackWithMin.h ChapterThree/StackWithMin.cpp ChapterThree/StackNode.h\
ChapterThree/RuntimeException.h
	$(CC) $(CFLAGS) ChapterThree/StackWithMin.cpp

ThreeStacksInOne_test.o: ThreeStacksInOne.o
	$(CC) $(CFLAGS) ChapterThree/ThreeStacksInOne_test.cpp

ThreeStacksInOne.o: ChapterThree/ThreeStacksInOne.h ChapterThree/ThreeStacksInOne.cpp
	$(CC) $(CFLAGS) ChapterThree/ThreeStacksInOne.cpp

#CH_FOUR_OBJ
BinaryTree_test.o: ChapterFour/AbstractTree.h ChapterFour/BinaryTree.h ChapterFour/TreeNode.h ChapterFour/BinaryTree_test.cpp
	$(CC) $(CFLAGS) ChapterFour/BinaryTree_test.cpp

GraphNode_test.o: ChapterFour/Node.h ChapterFour/GraphNode.h ChapterFour/GraphNode_test.cpp
	$(CC) $(CFLAGS) ChapterFour/GraphNode_test.cpp

Graph_test.o: ChapterFour/Graph.h ChapterFour/GraphNode.h ChapterFour/Graph_test.cpp
	$(CC) $(CFLAGS) ChapterFour/Graph_test.cpp

TreeNode_test.o: ChapterFour/TreeNode.h ChapterFour/Node.h ChapterFour/TreeNode_test.cpp
	$(CC) $(CFLAGS) ChapterFour/TreeNode_test.cpp

#CH_FIVE_OBJ
BitManipulator_test.o: ChapterFive/BitManipulator.h ChapterFive/StrangeArray.h ChapterFive/BitManipulator_test.cpp
	$(CC) $(CFLAGS) ChapterFive/BitManipulator_test.cpp

StrangeArray_test.o: StrangeArray.o
	$(CC) $(CFLAGS) ChapterFive/StrangeArray_test.cpp

StrangeArray.o: ChapterFive/StrangeArray.h ChapterFive/StrangeArray.cpp
	$(CC) $(CFLAGS) ChapterFive/StrangeArray.cpp

#CH_SEVEN_OBJ
CallHandle_test.o: CallHandle.o
	$(CC) $(CFLAGS) ChapterSeven/CallHandle_test.cpp

CallHandle.o: ChapterSeven/CallHandle.h ChapterSeven/CallHandle.cpp ChapterSeven/Fresher.h\
ChapterSeven/TechLead.h ChapterSeven/ProductManager.h ChapterSeven/Call.h ChapterSeven/Employee.h
	$(CC) $(CFLAGS) ChapterSeven/CallHandle.cpp

Employee_test.o: Employee.o
	$(CC) $(CFLAGS) ChapterSeven/Employee_test.cpp

Employee.o: ChapterSeven/Employee.h ChapterSeven/Employee.cpp ChapterSeven/CallHandle.h\
ChapterSeven/Call.h
	$(CC) $(CFLAGS) ChapterSeven/Employee.cpp

clean:
	rm -f *.o *~ CrackingTheCodingInterview


/*
 * ThreeStacksInOne.h
 *
 *  Created on: Nov 25, 2014
 *      Author: ubuntu
 */

#ifndef THREESTACKSINONE_H_
#define THREESTACKSINONE_H_
#include <vector>
#include <memory>
#include <list>
#include <stack>
#include "StackNode.h"

using namespace std;

namespace chapterThree {
//3.1:Describe how you could use a single array to implement three stacks.
class ThreeStacksInOne {
public:
	ThreeStacksInOne(int capacity);
	virtual ~ThreeStacksInOne();
	void push(int stackIndex, int value);
	int pop(int stackIndex);
	//3.6: Write a program to sort a stack in ascending order. You should not make any assump-
	//tions about how the stack is implemented. The following are the only functions that
	//should be used to write this program: push | pop | peek | isEmpty
	static stack<int> sortStack(stack<int> &original);
private:
	static int removeTop(stack<int> &stack);
	unique_ptr<StackNode[]> _stack;
	int _stackTop[3] = { -1, -1, -1 };
	list<int> _freeIndexes;
};

} /* namespace twotwo */
#endif /* THREESTACKSINONE_H_ */

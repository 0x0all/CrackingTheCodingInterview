/*
 * StackWithMin.h
 *
 *  Created on: Nov 24, 2014
 *      Author: ubuntu
 */

#ifndef STACKWITHMIN_H_
#define STACKWITHMIN_H_
#include <vector>
#include <stack>
#include "StackNode.h"

using namespace std;

namespace chapterThree {
//3.2:How would you design a stack which, in addition to push and pop, also has a function
//min which returns the minimum element? Push, pop and min should all operate in
//O(1) time.
class StackWithMin {
public:
	StackWithMin();
	virtual ~StackWithMin();
	int pop();
	void push(int value);
	int getMin();

private:
	stack<int, vector<StackNode>> _stack;
};

} /* namespace twotwo */
#endif /* STACKWITHMIN_H_ */

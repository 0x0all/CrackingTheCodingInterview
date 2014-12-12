/*
 * SetOfStacks.h
 *
 *  Created on: Nov 24, 2014
 *      Author: ubuntu
 */

#ifndef SETOFSTACKS_H_
#define SETOFSTACKS_H_

#include <vector>
#include <stack>
#include <iterator>

using namespace std;

namespace chapterThree {

typedef stack<int, vector<int>> IntStack;

class SetOfStacks {
public:
	SetOfStacks(int stackCapacity);
	virtual ~SetOfStacks();
	void push(int value);
	int pop();
	int getNumOfStacks();
private:
	int getCurrentTop();
	unsigned int _maxSize;
	vector<IntStack> _stacks;
	vector<IntStack>::iterator _currentStack;
};

} /* namespace threethree */
#endif /* SETOFSTACKS_H_ */

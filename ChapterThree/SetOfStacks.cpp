/*
 * SetOfStacks.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: ubuntu
 */

#include "SetOfStacks.h"
#include "RuntimeException.h"

namespace chapterThree {

SetOfStacks::SetOfStacks(int stackCapacity) :
		_maxSize(stackCapacity), _stacks(1), _currentStack(--_stacks.end()) {
}

SetOfStacks::~SetOfStacks() {
	// TODO Auto-generated destructor stub
}

void SetOfStacks::push(int value) {
	if (_currentStack->size() < _maxSize)
		_currentStack->push(value);
	else {
		_stacks.emplace_back(IntStack());
		_currentStack = --_stacks.end();
		_currentStack->push(value);
	}
}

int SetOfStacks::pop() {
	if (_stacks.empty())
		throw RuntimeException();
	if (_currentStack->empty()) {
		_stacks.pop_back();
		_currentStack = --_stacks.end();
	}
	return this->getCurrentTop();
}

int SetOfStacks::getCurrentTop() {
	int top = _currentStack->top();
	_currentStack->pop();
	return top;
}

int SetOfStacks::getNumOfStacks() {
	return _stacks.size();
}

} /* namespace threethree */

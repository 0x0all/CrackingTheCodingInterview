/*
 * StackWithMin.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: ubuntu
 */

#include "StackWithMin.h"
#include "RuntimeException.h"
#include <iostream>
#include <limits>
#include <memory>

using namespace std;

namespace chapterThree {

StackWithMin::StackWithMin() :
		_stack() {
}

StackWithMin::~StackWithMin() {
}

int StackWithMin::pop() {
	StackNode top = _stack.top();
	_stack.pop();
	return top.value;
}

void StackWithMin::push(int value) {
	if (_stack.size() == 0) {
		_stack.emplace(value, value);
	} else {
		_stack.emplace(value, min(value, _stack.top().localMin));
	}
}

int StackWithMin::getMin() {
	if (_stack.size() == 0)
		throw RuntimeException();
	StackNode top = _stack.top();
	return top.localMin;
}

} /* namespace twotwo */

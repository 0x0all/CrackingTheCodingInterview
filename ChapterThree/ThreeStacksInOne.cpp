/*
 * ThreeStacksInOne.cpp
 *
 *  Created on: Nov 25, 2014
 *      Author: ubuntu
 */
#include <numeric>
#include "ThreeStacksInOne.h"
#include "RuntimeException.h"

using namespace std;

namespace chapterThree {

ThreeStacksInOne::ThreeStacksInOne(int capacity) :
		_stack(new StackNode[capacity]), _freeIndexes(capacity) {
	iota(_freeIndexes.begin(), _freeIndexes.end(), 0);
}

ThreeStacksInOne::~ThreeStacksInOne() {}

stack<int> ThreeStacksInOne::sortStack(stack<int> &original) {
	stack<int> result;
	while (!original.empty()) {
		int nextTop = removeTop(original);
		while (!result.empty() && nextTop > result.top()) {
			original.push(removeTop(result));
		}
		result.push(nextTop);
	}
	return result;
}

int ThreeStacksInOne::removeTop(stack<int> &stack) {
	if (stack.empty())
		throw new RuntimeException();
	int top = stack.top();
	stack.pop();
	return top;
}

void ThreeStacksInOne::push(int stackIndex, int value) {
	auto previousTop = _stackTop[stackIndex];
	auto newTop = _freeIndexes.front();
	_freeIndexes.pop_front();
	_stackTop[stackIndex] = newTop;
	_stack[newTop].value = value;
	_stack[newTop].localMin = previousTop;
	_stack[newTop].stackIndex = stackIndex;
}

int ThreeStacksInOne::pop(int stackIndex) {
	auto topIndex = _stackTop[stackIndex];
	if (topIndex >= 0) {
		_freeIndexes.push_front(topIndex);
		auto top = _stack[topIndex];
		_stackTop[stackIndex] = top.localMin;
		return top.value;
	} else {
		throw RuntimeException();
	}
}

} /* namespace twotwo */

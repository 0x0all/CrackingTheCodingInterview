/*
 * StackNode.h
 *
 *  Created on: Nov 24, 2014
 *      Author: ubuntu
 */

#ifndef STACKNODE_H_
#define STACKNODE_H_
#include <iostream>
#include <memory>

using namespace std;

namespace chapterThree {

struct StackNode {
	int value;
	int localMin;
	int stackIndex;
	StackNode() :
			value(-1), localMin(-1), stackIndex(-1) {
	}
	StackNode(int val, int min) :
			value(val), localMin(min), stackIndex(0) {
	}
	StackNode(int val, int min, int stackIndex) :
			value(val), localMin(min), stackIndex(stackIndex) {
	}
	~StackNode() {
		//cout << "~StackNode()" <<endl;
	}
};
} /* namespace threethree */
#endif /* STACKNODE_H_ */

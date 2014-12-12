/*
 * StackWithMin_test.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: ubuntu
 */

#include <gtest/gtest.h>
#include "StackWithMin.h"
#include "RuntimeException.h"

using namespace std;

namespace chapterThree {

TEST(StackWithMin, PushPopSingleNumber) {
	StackWithMin stack;
	stack.push(1);
	ASSERT_EQ(1, stack.pop());
}

TEST(StackWithMin, PushPopThreeNumbers) {
	StackWithMin stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	ASSERT_EQ(3, stack.pop());
	ASSERT_EQ(2, stack.pop());
	ASSERT_EQ(1, stack.pop());
}

TEST(StackWithMin, GetMinNormal) {
	StackWithMin stack;
	stack.push(1);
	ASSERT_EQ(1, stack.getMin());
}

TEST(StackWithMin, GetMinTwoElements) {
	StackWithMin stack;
	stack.push(1);
	stack.push(-1);
	ASSERT_EQ(-1, stack.getMin());
}

TEST(StackWithMin, GetMinThreeElements) {
	StackWithMin stack;
	stack.push(2);
	stack.push(-1);
	stack.push(1);
	ASSERT_EQ(-1, stack.getMin());
}

TEST(StackWithMin, GetMinThreeElementsPop) {
	StackWithMin stack;
	stack.push(1);
	stack.push(2);
	stack.push(-3);
	ASSERT_EQ(-3, stack.getMin());
	ASSERT_EQ(-3, stack.pop());
	ASSERT_EQ(1, stack.getMin());
}

TEST(StackWithMin, GetMinException) {
	StackWithMin stack;
	ASSERT_THROW(stack.getMin(), RuntimeException);
}

} /* namespace twotwo */

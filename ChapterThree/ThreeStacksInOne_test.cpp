/*
 * ThreeStacksInOne_test.cpp
 *
 *  Created on: Nov 25, 2014
 *      Author: ubuntu
 */
#include <gtest/gtest.h>
#include "ThreeStacksInOne.h"

namespace chapterThree {

TEST(ThreeStacksInOne, SinglePushPop) {
	ThreeStacksInOne stack(1);
	stack.push(0, 1);
	ASSERT_EQ(1, stack.pop(0));
}

TEST(ThreeStacksInOne, SingleStackMultiPushPop) {
	ThreeStacksInOne stack(3);
	stack.push(0, 1);
	stack.push(0, 2);
	stack.push(0, 3);
	ASSERT_EQ(3, stack.pop(0));
	ASSERT_EQ(2, stack.pop(0));
	ASSERT_EQ(1, stack.pop(0));
}

TEST(ThreeStacksInOne, MultiStackMultiPushPop) {
	ThreeStacksInOne stack(4);
	stack.push(0, 1);
	stack.push(0, 2);
	stack.push(1, 1);
	stack.push(1, 2);
	ASSERT_EQ(2, stack.pop(0));
	ASSERT_EQ(2, stack.pop(1));
	ASSERT_EQ(1, stack.pop(0));
	ASSERT_EQ(1, stack.pop(1));
}

TEST(ThreeStacksInOne, SortStack) {
	stack<int> original;
	original.push(3);
	original.push(2);
	stack<int> sorted = ThreeStacksInOne::sortStack(original);
	ASSERT_FALSE(sorted.empty());
	ASSERT_EQ(2, sorted.top());
	sorted.pop();
	ASSERT_EQ(3, sorted.top());
	sorted.pop();
}

TEST(ThreeStacksInOne, SortStackThreeElements) {
	stack<int> original;
	original.push(3);
	original.push(2);
	original.push(1);
	stack<int> sorted = ThreeStacksInOne::sortStack(original);
	ASSERT_FALSE(sorted.empty());
	ASSERT_EQ(1, sorted.top());
	sorted.pop();
	ASSERT_EQ(2, sorted.top());
	sorted.pop();
	ASSERT_EQ(3, sorted.top());
	sorted.pop();
}

TEST(ThreeStacksInOne, SortStackThreeElementsReverse) {
	stack<int> original;
	original.push(1);
	original.push(2);
	original.push(3);
	stack<int> sorted = ThreeStacksInOne::sortStack(original);
	ASSERT_FALSE(sorted.empty());
	ASSERT_EQ(1, sorted.top());
	sorted.pop();
	ASSERT_EQ(2, sorted.top());
	sorted.pop();
	ASSERT_EQ(3, sorted.top());
	sorted.pop();
}

TEST(ThreeStacksInOne, SortStackThreeElementsSame) {
	stack<int> original;
	original.push(1);
	original.push(1);
	original.push(1);
	stack<int> sorted = ThreeStacksInOne::sortStack(original);
	ASSERT_FALSE(sorted.empty());
	ASSERT_EQ(1, sorted.top());
	sorted.pop();
	ASSERT_EQ(1, sorted.top());
	sorted.pop();
	ASSERT_EQ(1, sorted.top());
	sorted.pop();
}

} /* namespace twotwo */

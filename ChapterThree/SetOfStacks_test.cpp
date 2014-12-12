/*
 * SetOfStacks_test.cpp
 *
 *  Created on: Nov 24, 2014
 *      Author: ubuntu
 */

#include <gtest/gtest.h>
#include "SetOfStacks.h"

using namespace std;

namespace chapterThree {

TEST(SetoOfStacks, Creation) {
	SetOfStacks set(0);
}

TEST(SetoOfStacks, NumOfStacks) {
	SetOfStacks set(0);
	ASSERT_EQ(1, set.getNumOfStacks());
}

TEST(SetoOfStacks, PushPop) {
	SetOfStacks set(1);
	set.push(1);
	ASSERT_EQ(1, set.pop());
	set.push(2);
	ASSERT_EQ(2, set.pop());
}

TEST(SetoOfStacks, AddStack) {
	SetOfStacks set(2);
	set.push(1);
	set.push(2);
	set.push(3);
	ASSERT_EQ(2, set.getNumOfStacks());
}

TEST(SetoOfStacks, PopFromMultiple) {
	SetOfStacks set(2);
	set.push(1);
	set.push(2);
	set.push(3);
	ASSERT_EQ(2, set.getNumOfStacks());
	ASSERT_EQ(3, set.pop());
	ASSERT_EQ(2, set.pop());
	ASSERT_EQ(1, set.pop());
	ASSERT_EQ(1, set.getNumOfStacks());
}

} /* namespace threethree */

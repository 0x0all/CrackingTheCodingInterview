/*
 * StrangeArray_test.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: ubuntu
 */
#include <gtest/gtest.h>
#include <limits>
#include "StrangeArray.h"

using namespace std;

namespace chapterFive {

TEST(StrangeArrayTest, StrangeArrayCreation){
	StrangeArray data(2, 1);
	ASSERT_EQ(2, data.size());
}

TEST(StrangeArrayTest, StrangeArrayFetch){
	StrangeArray data(5, 4);
	ASSERT_EQ(0, data.fetch(0,0));
	ASSERT_EQ(0, data.fetch(0,31));
	ASSERT_EQ(1, data.fetch(1,0));
	ASSERT_EQ(1, data.fetch(2,1));
	ASSERT_EQ(1, data.fetch(3,0));
	ASSERT_EQ(1, data.fetch(3,1));
	ASSERT_EQ(1, data.fetch(4,0));
	ASSERT_EQ(1, data.fetch(4,2));
}

} /* namespace chapterFive */

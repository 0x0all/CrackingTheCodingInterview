/*
 * BitManipulator_test.cpp
 *
 *  Created on: Dec 18, 2014
 *      Author: ubuntu
 */
#include <gtest/gtest.h>
#include "BitManipulator.h"
#include <limits>

using namespace std;

namespace chapterFive {

TEST(BitManipulatorTest, MakeSubstringHappyFlowOne){
	unsigned int maxInt = numeric_limits<int>::max();
	unsigned int five = 5;
	ASSERT_EQ(maxInt - 2, BitManipulator::makeSubstring(maxInt, five, 0, 2));
}

TEST(BitManipulatorTest, MakeSubstringHappyFlowTwo){
	unsigned int maxInt = numeric_limits<int>::max();
	unsigned int five = 5;
	ASSERT_EQ(maxInt - 4, BitManipulator::makeSubstring(maxInt, five, 1, 3));
}

TEST(BitManipulatorTest, MakeSubstringHappyFlowThree){
	unsigned int maxInt = numeric_limits<int>::max();
	unsigned int five = 5;
	ASSERT_EQ(maxInt - 8, BitManipulator::makeSubstring(maxInt, five, 2, 4));
}

} /* namespace chapterFive */

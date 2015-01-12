/*
 * BitManipulator.h
 *
 *  Created on: Dec 18, 2014
 *      Author: ubuntu
 */

#ifndef BITMANIPULATOR_H_
#define BITMANIPULATOR_H_
#include <limits>
#include <math.h>

using namespace std;

namespace chapterFive {

class BitManipulator {
public:
	BitManipulator(){}
	virtual ~BitManipulator(){}

//	5.1 You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a
//	method to set all bits between i and j in N equal to M
	static unsigned int makeSubstring(unsigned int original, unsigned int subNum, int startPos, int endPos){
		unsigned int maxInt = numeric_limits<int>::max();
		unsigned int left = maxInt - ((1 << (endPos+1)) - 1);
		unsigned int right = (1 << (startPos)) - 1;
		unsigned int mask = left | right;
		return (original & mask) | (subNum << startPos);
	}

//	5.3 Given an integer, print the next smallest and next largest number that have the same
//	number of 1 bits in their binary representation.
	static unsigned int getNextBiggerWithSameNumberOfOnes(unsigned int original){
		int index = 0;
		while(index < 31){
			if(getBitAt(original, index) == 1 && getBitAt(original, index+1) == 0){
				turnOnAt(original, index+1);
				turnOffAt(original, index);
				return shrink(original, index);
			}
			++index;
		}
		return 0;
	}

//	5.3 Given an integer, print the next smallest and next largest number that have the same
//	number of 1 bits in their binary representation.
	static unsigned int getNextSmallerWithSameNumberOfOnes(unsigned int original){
		int index = 0;
		while(index < 32){
			if(getBitAt(original, index) == 0 && getBitAt(original,index+1) == 1){
				turnOnAt(original, index);
				turnOffAt(original, index+1);
				return enlarge(original, index);
			}
			++index;
		}
		return 0;
	}

//	5.5 Write a function to determine the number of bits required to convert integer A to
//	integer B.
	static int findNumberOrBitChanges(unsigned int source, unsigned int target){
		return countOnes(source ^ target);
	}

//	5.6 Write a program to swap odd and even bits in an integer with as few instructions as
//	possible
	static unsigned int swapEvenOdd(unsigned int source){
		return ((source >> 1) & 0x55555555) | ((source << 1) & 0xaaaaaaaa);
	}

private:
	static unsigned int getBitAt(unsigned int number, int index){
		return (number & (1 << index)) > 0 ? 1 : 0;
	}

	static void turnOnAt(unsigned int &number, int index){
		setBit(number, index, true);
	}

	static void turnOffAt(unsigned int &number, int index){
		setBit(number, index, false);
	}

	static void setBit(unsigned int &number, int index, bool isTrue){
		if(isTrue)
			number = number  | (1 << index);
		else
			number = number & ~(1 << index);
	}

	static unsigned int shrink(unsigned int original, int suffixPosition){
		int index = 0;
		while(index < suffixPosition){
			if(getBitAt(original, index) == 0 && getBitAt(original,index+1) == 1){
				turnOnAt(original, index);
				turnOffAt(original,index+1);
				original = shrink(original, index);
			}
			++index;
		}
		return original;
	}

	static unsigned int enlarge(unsigned int original, int suffixPosition){
		int index = suffixPosition;
		while(index > 0){
			if(getBitAt(original, index) == 0 && getBitAt(original, index-1) == 1){
				turnOnAt(original, index);
				turnOffAt(original,index-1);
				original = enlarge(original,suffixPosition);
			}
			--index;
		}
		return original;
	}

	static int countOnes(unsigned int num){
		int ones = 0;
		int cnt = 0;
		while(cnt < 32){
			if(num % 2)
				++ones;
			num = num >> 1;
			cnt++;
		}
		return ones;
	}
};

} /* namespace chapterFive */
#endif /* BITMANIPULATOR_H_ */

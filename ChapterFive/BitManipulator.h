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
	static unsigned int makeSubstring(unsigned int original, unsigned int subNum, int startPos, int endPos){
		unsigned int maxInt = numeric_limits<int>::max();
		unsigned int left = maxInt - ((1 << (endPos+1)) - 1);
		unsigned int right = (1 << (startPos)) - 1;
		unsigned int mask = left | right;
		return (original & mask) | (subNum << startPos);
	}

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
};

} /* namespace chapterFive */
#endif /* BITMANIPULATOR_H_ */

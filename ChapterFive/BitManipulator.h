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
		unsigned int mask = 3;
		for(int i = 0; i < 30; i++){
			if((original & mask) == pow(2,i)){
				unsigned int andMask = numeric_limits<unsigned int>::max() - pow(2,i);
				unsigned int orMask = pow(2,i+1);
				return (original & andMask) | orMask;
			}
			mask = mask << 1;
		}
		return 0;
	}

	static unsigned int getNextSmallerWithSameNumberOfOnes(unsigned int original){
			unsigned int mask = 3;
			for(int i = 0; i < 30; i++){
				if((original & mask) == pow(2,i+1)){
					unsigned int andMask = numeric_limits<unsigned int>::max() - pow(2,i+1);
					unsigned int orMask = pow(2,i);
					return (original & andMask) | orMask;
				}
				mask = mask << 1;
			}
			return 0;
		}
};

} /* namespace chapterFive */
#endif /* BITMANIPULATOR_H_ */

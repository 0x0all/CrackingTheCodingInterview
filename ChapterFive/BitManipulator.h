/*
 * BitManipulator.h
 *
 *  Created on: Dec 18, 2014
 *      Author: ubuntu
 */

#ifndef BITMANIPULATOR_H_
#define BITMANIPULATOR_H_
#include <limits>

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
};

} /* namespace chapterFive */
#endif /* BITMANIPULATOR_H_ */

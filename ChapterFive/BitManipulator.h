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
#include <sstream>
#include <stack>
#include "StrangeArray.h"

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

//	5.2 Given a (decimal - e.g. 3.72) number that is passed in as a string, print the binary rep-
//	resentation. If the number can not be represented accurately in binary, print “ERROR”
	static string printDecimal(string number){
		unsigned int pointPos = number.find(".");
		if(pointPos == string::npos)
			return "ERROR";

		int integerPart = parseIntPart(number, pointPos);
		double decimalPart = parseDecimalPart(number, pointPos);
		stack<string> intBitStack = createIntBitStack(integerPart);
		stack<string> decimalBitStack = createDecimalBitStack(decimalPart);
		if(decimalBitStack.size() > 32)
			return "ERROR";

		stringstream result;
		pushStackToStream(intBitStack, result);
		result << ".";
		pushStackToStream(decimalBitStack, result);

		return result.str();
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

//	5.7 An array A[1...n] contains all the integers from 0 to n except for one number which is
//	missing. In this problem, we cannot access an entire integer in A with a single opera-
//	tion. The elements of A are represented in binary, and the only operation we can use
//	to access them is “fetch the jth bit of A[i]”, which takes constant time. Write code to
//	find the missing integer.
	static int findMissingInt(StrangeArray array){
		int maxInt = array.size();
		int correntSum = maxInt * (maxInt+1) / 2;
		int sum = 0;
		for(unsigned int index = 0; index < array.size(); index++){
			for(unsigned int bit =0; bit<32; bit++){
						sum += array.fetch(index, bit) * pow(2, bit);
					}
		}
		return correntSum - sum;
	}

private:
	static int parseIntPart(const string& number, unsigned int pointPos) {
		string intPart = number.substr(0, pointPos);
		int integerPart = stoi(intPart);
		return integerPart;
	}

	static double parseDecimalPart(const string& number, unsigned int pointPos) {
		string decPart = "0" + number.substr(pointPos);
		double decimalPart = stod(decPart);
		return decimalPart;
	}

	static stack<string> createIntBitStack(int integerPart){
		stack<string> intBitStack;
		while(integerPart > 0){
			if(integerPart % 2 == 0)
				intBitStack.push("0");
			else
				intBitStack.push("1");
			integerPart >>= 1;
		}
		return intBitStack;
	}

	static stack<string> createDecimalBitStack(double decimalPart){
		stack<string> decimalBitStack;
		while(decimalPart > 0){
			double r = decimalPart;
			r *= 2;
			if(r >= 1){
				decimalBitStack.push("1");
				decimalPart = r - 1;
			}
			else{
				decimalBitStack.push("0");
				decimalPart = r;
			}
		}
		return decimalBitStack;
	}

	static void pushStackToStream(stack<string>& stackToPush, stringstream& result) {
		while (!stackToPush.empty()) {
			result << stackToPush.top();
			stackToPush.pop();
		}
	}

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

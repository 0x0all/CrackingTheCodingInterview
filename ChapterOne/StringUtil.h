/*
 * UniqueStringChecker.h
 *
 *  Created on: Nov 13, 2014
 *      Author: ubuntu
 */

#ifndef UNIQUESTRINGCHECKER_H_
#define UNIQUESTRINGCHECKER_H_
#include <string>
#include <memory>

using namespace std;

namespace chapterOne {

class StringUtil {
public:
	StringUtil();
	virtual ~StringUtil();
//	1.1: Implement an algorithm to determine if a string has all unique characters.
	static bool hasAllUniqueCharacters(const char *string);
//	1.1: What if you can not use additional data structures?
	static bool hasAllUniqueCharacters(const std::string& string);
//	1.2: Write code to reverse a C-Style String. (C-String means that “abcd” is represented as
//	five characters, including the null character.)
	static const char* reverseInPlace(char *string);
//	1.3: Design an algorithm and write code to remove the duplicate characters in a string
//	without using any additional buffer. NOTE: One or two additional variables are fine.
//	An extra copy of the array is not.
	static void removeDuplicatesInPlace(char *string);
//	1.4: Write a method to decide if two strings are anagrams or not.
	static bool areAnagrams(const char*one, const char*other);
//	1.5: Write a method to replace all spaces in a string with ‘%20’.
	static unique_ptr<char[]> replaceAllSpaces(const char *str);
//	1.6: Given an image represented by an NxN matrix, where each pixel in the image is 4
//	bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
	static char** rotateMatrix(char **matrix, int size, int angle);
//	1.7: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
//	column is set to 0.
	static void addZeros(int** matrix, int rows, int cols);
private:
	static bool isNullChar(const char *string);
	static bool charIsKnown(bool *charMap, const char character);
	static void advanceToLastCharacter(char *&charPtr);
	static void swap(char *one, char *other);
	static bool innerOccuranceRemoved(const char candidate, char * string);
	static void shiftStringLeft(char * dublicate);
	static void countCharOccurance(const char *string, int *characterOccuranceArray, int *unmachedUniqueChars);
	static bool characterMatched(const char character, int *characterOccuranceArray, int *unmachedUniqueChars);
	static void replaceCharacter(char *newString, int *newStringIndex, const char *origilString,  const int originalStringIndex);
	static void countNumOfSpaces(const char *string, int *numOfSpaces, int *stringSize);
	static void swapMatrix(char** matrix, int row, int column, int size,
			int angle, int depth);
	static void swapStep(char** matrix, int row, int column, int size,
			int depth);
	static char replaceStep(char **matrix, char newChar, int row, int column);
	static void MoveLeftOriginToDublicate(char *origin, char *dublicate);

};
}
#endif /* UNIQUESTRINGCHECKER_H_ */

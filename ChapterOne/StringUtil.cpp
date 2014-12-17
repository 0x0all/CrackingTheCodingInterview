/*
 * UniqueStringChecker.cpp
 *
 *  Created on: Nov 13, 2014
 *      Author: ubuntu
 */

#include "StringUtil.h"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

namespace chapterOne {

StringUtil::StringUtil() {}

StringUtil::~StringUtil() {}

bool StringUtil::hasAllUniqueCharacters(const char *string) {
	if (isNullChar(string))
		return true;

	bool charMap[255] = { false };

	for (; *string; string++) {
		if(charIsKnown(charMap, *string))
			return false;
	}

	return true;
}

bool StringUtil::isNullChar(const char *string){
	return *string == '\0' ? true : false;
}

bool StringUtil::charIsKnown(bool *charMap, const char character){
	if (charMap[(int)character])
		return true;
	charMap[(int)character] = true;
	return false;
}

bool StringUtil::hasAllUniqueCharacters(const std::string& str) {
	auto begin = str.cbegin();
	auto end = str.cend();
	for (; begin != end; begin++) {
		if (find(begin +1, end, *begin) != end)
			return false;
	}
	return true;
}

const char* StringUtil::reverseInPlace(char *string) {
	char *origin = string;
	char *last = string;
	if (*string) {
		advanceToLastCharacter(last);
		while (string < last) {
			swap(string++, last--);
		}
	}
	return origin;
}

void StringUtil::advanceToLastCharacter(char *&charPtr){
	for (; *charPtr; charPtr++) {}
	--charPtr;
}

void StringUtil::swap(char *one, char *other){
	char tmp;
	tmp = *one;
	*one = *other;
	*other = tmp;
}

void StringUtil::removeDuplicatesInPlace(char *string) {
	for (; *string; string++) {
		if (innerOccuranceRemoved(*string, string+1))
				shiftStringLeft(string);
	}
}

bool StringUtil::innerOccuranceRemoved(const char candidate, char * string){
	bool dublicateRemoved = false;
	while (*string) {
		if (candidate == *string) {
			shiftStringLeft(string);
			dublicateRemoved = true;
		} else
			++string;
	}
	return dublicateRemoved;
}

void StringUtil::shiftStringLeft(char * startIndex) {
	for (; *startIndex; startIndex++)
		*startIndex = *(startIndex + 1);
}

bool StringUtil::areAnagrams(const char*one, const char*other) {
	if (isNullChar(one) || isNullChar(other))
		return false;

	int charOccuranceCounter[255] = { 0 };
	int unmachedUniqueChars = 0;

	countCharOccurance(one, charOccuranceCounter, &unmachedUniqueChars);

	for (; *other; other++) {
		if(!characterMatched(*other, charOccuranceCounter, &unmachedUniqueChars))
			return false;
	}
	return unmachedUniqueChars == 0;
}

void StringUtil::countCharOccurance(const char *string, int *characterOccuranceArray, int *unmachedUniqueChars){
	for (; *string; string++) {
		if (characterOccuranceArray[(int) *string] == 0)
			*unmachedUniqueChars += 1;
		characterOccuranceArray[(int) *string] += 1;
	}
}

bool StringUtil::characterMatched(const char character, int *characterOccuranceArray, int *unmachedUniqueChars){
	if (characterOccuranceArray[(int) character] == 0)
		return false;

	characterOccuranceArray[(int) character] -= 1;
	if (characterOccuranceArray[(int) character] == 0)
		*unmachedUniqueChars -= 1;

	return true;
}

unique_ptr<char[]> StringUtil::replaceAllSpaces(const char *str) {
	if (isNullChar(str))
		return unique_ptr<char[]>(new char{'\0'});

	int numOfSpaceChars = 0;
	int numOfOriginalChars = 0;

	countNumOfSpaces(str, &numOfSpaceChars, &numOfOriginalChars);

	int totalNumOfChars = numOfOriginalChars + 2 * numOfSpaceChars;
	unique_ptr<char[]> array(new char[totalNumOfChars + 1]);

	int lastNewCharIndex = totalNumOfChars - 1;
	int lastOriginalCharIndex = numOfOriginalChars -1;

	array.get()[lastNewCharIndex + 1] = '\0';
	for (; lastOriginalCharIndex >= 0; lastOriginalCharIndex--, lastNewCharIndex--)
		replaceCharacter(array.get(), &lastNewCharIndex, str, lastOriginalCharIndex);
	return array;
}

void StringUtil::countNumOfSpaces(const char *string, int *numOfSpaces, int *stringSize){
	for (; *string; string++, (*stringSize)++) {
		if (*string == ' ')
			*numOfSpaces += 1;
	}
}

void StringUtil::replaceCharacter(char *newString, int *newStringIndex, const char *origilString,  const int originalStringIndex){
	if (origilString[originalStringIndex] == ' ') {
		newString[(*newStringIndex)--] = '0';
		newString[(*newStringIndex)--] = '2';
		newString[*newStringIndex] = '%';
	} else
		newString[*newStringIndex] = origilString[originalStringIndex];
}

char** StringUtil::rotateMatrix(char **matrix, int size, int angle) {
	int depth = 0;
	while (depth < size - 1) {
		swapMatrix(matrix, 0, 0, size, angle, depth);
		--size;
		++depth;
	}

	return matrix;
}

void StringUtil::swapMatrix(char **matrix, int row, int col, int size,
		int angle, int depth) {
	int times = angle / 45;
	while (times > 0) {
		for (int guidCol = 0; guidCol < size - 1 - depth; guidCol++) {
			swapStep(matrix, row, guidCol, size, depth);
		}
		--times;
	}
}

void StringUtil::swapStep(char **matrix, int row, int column, int size,
		int depth) {
	int startRow = row + depth;
	int startCol = column + depth;
	char firstChar = matrix[startRow * sizeof(char)][startCol * sizeof(char)];
	char replaced = replaceStep(matrix, firstChar, startRow + column, size - 1);
	replaced = replaceStep(matrix, replaced, size - 1, size - 1 - column);
	replaced = replaceStep(matrix, replaced, size - 1 - column, startRow);
	replaced = replaceStep(matrix, replaced, startRow, startRow + column);
}

char StringUtil::replaceStep(char **matrix, char newChar, int row,
		int column) {
	char tmp = matrix[row * sizeof(char)][column * sizeof(char)];
	matrix[row * sizeof(char)][column * sizeof(char)] = newChar;
	return tmp;
}


void StringUtil::addZeros(int** matrix, int rows, int cols) {
	vector<bool> zeroRows(rows, false);
	vector<bool> zeroCols(cols, false);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] == 0) {
				zeroRows[i] = true;
				zeroCols[j] = true;
			}
		}
	}

	for (int i = 0; i < rows; i++) {
		if (zeroRows[i]) {
			for (int j = 0; j < cols; j++)
				matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < cols; i++) {
		if (zeroCols[i]) {
			for (int j = 0; j < cols; j++)
				matrix[j][i] = 0;
		}
	}

}


}


//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "StringUtil.h"

using namespace std;

namespace chapterOne {

TEST(StringUtilTest, EmptyCharPointer) {
	const char *str = "";
	ASSERT_TRUE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, SingleChar) {
	const char *str = "a";
	ASSERT_TRUE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, TwoDifferentChars) {
	const char *str = "ab";
	ASSERT_TRUE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, TwoIdenticalChars) {
	const char *str = "aa";
	ASSERT_FALSE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, ThreeDifferentChars) {
	const char *str = "abc";
	ASSERT_TRUE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, IdenticalPrefix) {
	const char *str = "aab";
	ASSERT_FALSE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, IdenticalSuffix) {
	const char *str = "baa";
	ASSERT_FALSE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, RandomDoubleCharacter) {
	const char *str = "bacad";
	ASSERT_FALSE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, EmptyString) {
	string str = "";
	ASSERT_TRUE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, SingleCharacterString) {
	string str = "a";
	ASSERT_TRUE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, IdenticalPrefixString) {
	string str = "aab";
	ASSERT_FALSE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, IdenticalSuffixString) {
	string str = "baa";
	ASSERT_FALSE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, RandomDoubleString) {
	string str = "bacad";
	ASSERT_FALSE(StringUtil::hasAllUniqueCharacters(str));
}

TEST(StringUtilTest, ReverseEmpty) {
	char str[] = "";
	ASSERT_STREQ("", StringUtil::reverseInPlace(str));
}

TEST(StringUtilTest, ReverseSingleChar) {
	char str[] = "a";
	ASSERT_STREQ("a", StringUtil::reverseInPlace(str));
}

TEST(StringUtilTest, ReverseTwoChar) {
	char str[] = "ab";
	ASSERT_STREQ("ba", StringUtil::reverseInPlace(str));
}

TEST(StringUtilTest, RemoveDulpicatesEmpty) {
	char str[] = "";
	StringUtil::removeDuplicatesInPlace(str);
	ASSERT_STREQ("", str);
}

TEST(StringUtilTest, RemoveDulpicatesNoDuplicates) {
	char str[] = "ab";
	StringUtil::removeDuplicatesInPlace(str);
	ASSERT_STREQ("ab", str);
}

TEST(StringUtilTest, RemoveDulpicatesOneDuplicate) {
	char str[] = "aa";
	StringUtil::removeDuplicatesInPlace(str);
	ASSERT_STREQ("", str);
}

TEST(StringUtilTest, RemoveDulpicatesOneDuplicateWithSuffix) {
	char str[] = "aab";
	StringUtil::removeDuplicatesInPlace(str);
	ASSERT_STREQ("b", str);
}

TEST(StringUtilTest, RemoveDulpicatesOneDuplicateWithPrefix) {
	char str[] = "baa";
	StringUtil::removeDuplicatesInPlace(str);
	ASSERT_STREQ("b", str);
}

TEST(StringUtilTest, RemoveDulpicatesOneDuplicateBetween) {
	char str[] = "baac";
	StringUtil::removeDuplicatesInPlace(str);
	ASSERT_STREQ("bc", str);
}

TEST(StringUtilTest, RemoveDulpicatesOneTriplet) {
	char str[] = "aaa";
	StringUtil::removeDuplicatesInPlace(str);
	ASSERT_STREQ("", str);
}

TEST(StringUtilTest, areAnagramsEmpty) {
	char one[] = "";
	char other[] = "";
	ASSERT_FALSE(StringUtil::areAnagrams(one, other));
}

TEST(StringUtilTest, areAnagramsOneEmpty) {
	char one[] = "";
	char other[] = "a";
	ASSERT_FALSE(StringUtil::areAnagrams(one, other));
}

TEST(StringUtilTest, areAnagramsSigleChars) {
	char one[] = "a";
	char other[] = "a";
	ASSERT_TRUE(StringUtil::areAnagrams(one, other));
}

TEST(StringUtilTest, areAnagramsHappyFlowSmall) {
	char one[] = "ab";
	char other[] = "ba";
	ASSERT_TRUE(StringUtil::areAnagrams(one, other));
}

TEST(StringUtilTest, areAnagramsHappyFlowLarge) {
	char one[] = "abcdef";
	char other[] = "fcbaed";
	ASSERT_TRUE(StringUtil::areAnagrams(one, other));
}

TEST(StringUtilTest, areAnagramsFalseFlow) {
	char one[] = "ac";
	char other[] = "ba";
	ASSERT_FALSE(StringUtil::areAnagrams(one, other));
}

TEST(StringUtilTest, areAnagramsFalseFlowLarge) {
	char one[] = "abcdef";
	char other[] = "fcbied";
	ASSERT_FALSE(StringUtil::areAnagrams(one, other));
}

TEST(StringUtilTest, areAnagramsFalseFlowDifferentsize) {
	char one[] = "ac";
	char other[] = "cab";
	ASSERT_FALSE(StringUtil::areAnagrams(one, other));
}

TEST(StringUtilTest, replaceFunEmpty) {
	char one[] = "";
	ASSERT_STREQ("", StringUtil::replaceAllSpaces(one).get());
}

TEST(StringUtilTest, replaceFunOneSpace) {
	char one[] = " ";
	ASSERT_STREQ("%20", StringUtil::replaceAllSpaces(one).get());
}

TEST(StringUtilTest, replaceFunSpaceSuffix) {
	char one[] = "a ";
	ASSERT_STREQ("a%20", StringUtil::replaceAllSpaces(one).get());
}

TEST(StringUtilTest, replaceFunSpacePrefix) {
	char one[] = " a";
	ASSERT_STREQ("%20a", StringUtil::replaceAllSpaces(one).get());
}

TEST(StringUtilTest, replaceFunSpaceMultiple) {
	char one[] = "a b c ";
	ASSERT_STREQ("a%20b%20c%20", StringUtil::replaceAllSpaces(one).get());
}

TEST(StringUtilTest, rotateMatrix2x2) {
	char first[] = "ab";
	char second[] = "cd";
	char *matrix[2] = { first, second };

	char res_first[] = "dc";
	char res_second[] = "ba";
	char *res_matrix[2] = { res_first, res_second };

	char **result = StringUtil::rotateMatrix(matrix, 2, 90);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ASSERT_EQ(res_matrix[i * sizeof(char)][j * sizeof(char)],
					result[i * sizeof(char)][j * sizeof(char)]);
		}
	}
}

TEST(StringUtilTest, rotateMatrix3x3) {
	int size = 3;
	char first[] = "abc";
	char second[] = "def";
	char third[] = "ghi";
	char *matrix[3] = { first, second, third };

	char res_first[] = "ihg";
	char res_second[] = "fed";
	char res_third[] = "cba";
	char *res_matrix[3] = { res_first, res_second, res_third };

	char **result = StringUtil::rotateMatrix(matrix, size, 90);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			ASSERT_EQ(res_matrix[i * sizeof(char)][j * sizeof(char)],
					result[i * sizeof(char)][j * sizeof(char)]);
		}
	}
}

TEST(StringUtilTest, rotateMatrix4x4) {
	int size = 4;
	char first[] = "abcd";
	char second[] = "efgh";
	char third[] = "ijkl";
	char fourth[] = "mnop";
	char *matrix[4] = { first, second, third, fourth };

	char res_first[] = "ponm";
	char res_second[] = "lkji";
	char res_third[] = "hgfe";
	char res_fourth[] = "dcba";
	char *res_matrix[4] = { res_first, res_second, res_third, res_fourth };

	char **result = StringUtil::rotateMatrix(matrix, size, 90);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			ASSERT_EQ(res_matrix[i * sizeof(char)][j * sizeof(char)],
					result[i * sizeof(char)][j * sizeof(char)]);
		}
	}
}

TEST(StringUtilTest, zeroMatrix1x1) {
	int cols = 1;
	int rows = 1;

	int rowOne[] = { 1 };
	int *matrix[] = { rowOne };

	int res_rowOne[] = { 1 };
	int *res_matrix[] = { res_rowOne };

	StringUtil::addZeros(matrix, rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ASSERT_EQ(res_matrix[i][j], matrix[i][j]);
		}
	}
}

TEST(StringUtilTest, zeroMatrix2x2) {
	int cols = 2;
	int rows = 2;

	int rowOne[] = { 1, 0 };
	int rowTwo[] = { 1, 1 };
	int *matrix[] = { rowOne, rowTwo };

	int res_rowOne[] = { 0, 0 };
	int res_rowTwo[] = { 1, 0 };
	int *res_matrix[] = { res_rowOne, res_rowTwo };

	StringUtil::addZeros(matrix, rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ASSERT_EQ(res_matrix[i][j], matrix[i][j]);
		}
	}
}

TEST(StringUtilTest, zeroMatrix3x3) {
	int cols = 3;
	int rows = 3;

	int rowOne[] = { 1, 1, 1 };
	int rowTwo[] = { 1, 0, 1 };
	int rowThree[] = { 1, 1, 1 };
	int *matrix[] = { rowOne, rowTwo, rowThree };

	int res_rowOne[] = { 1, 0, 1 };
	int res_rowTwo[] = { 0, 0, 0 };
	int res_rowThree[] = { 1, 0, 1 };
	int *res_matrix[] = { res_rowOne, res_rowTwo, res_rowThree };

	StringUtil::addZeros(matrix, rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ASSERT_EQ(res_matrix[i][j], matrix[i][j]);
		}
	}
}
}

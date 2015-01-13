/*
 * StrangeArray.h
 *
 *  Created on: Jan 13, 2015
 *      Author: ubuntu
 */

#ifndef STRANGEARRAY_H_
#define STRANGEARRAY_H_

#include <vector>
#include <bitset>

namespace chapterFive {

using namespace std;

class StrangeArray {
public:
	StrangeArray(int maxInt, int missingInt);
	virtual ~StrangeArray();
	unsigned int fetch(unsigned int index, unsigned int bit);
	unsigned int size();
private:
	vector<bitset<32>> data;
};

} /* namespace chapterFive */
#endif /* STRANGEARRAY_H_ */

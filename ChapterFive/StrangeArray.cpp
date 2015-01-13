/*
 * StrangeArray.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: ubuntu
 */

#include "StrangeArray.h"

namespace chapterFive {

StrangeArray::StrangeArray(int maxInt, int missingInt):data() {
	for(int i = 0; i <= maxInt; i++){
		if(i != missingInt){
			data.emplace_back(i);
		}
	}
}

StrangeArray::~StrangeArray() {
	// TODO Auto-generated destructor stub
}

unsigned int StrangeArray::fetch(unsigned int index, unsigned int bit){
	if(index < size() && bit < 32)
		return data[index].test(bit) ? 1 : 0;
	return 0;
}

unsigned int StrangeArray::size(){
	return data.size();
}

} /* namespace chapterFive */

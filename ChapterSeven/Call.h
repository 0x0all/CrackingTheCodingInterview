/*
 * Call.h
 *
 *  Created on: Dec 17, 2014
 *      Author: ubuntu
 */

#ifndef CALL_H_
#define CALL_H_
#include <string>

using namespace std;

namespace chapterSeven {

class Call {
public:
	Call(int rank):Rank(rank){}
	virtual ~Call(){}
	int Rank;
	string HandledBy;
	virtual bool handle(int rank)=0;
};

class RankedCall:public Call {
public:
	RankedCall(int rank):Call(rank){}
	virtual ~RankedCall(){}
	bool handle(int rank){return rank == Rank;}
};

class DispatchedToLevelTwoCall:public Call {
public:
	DispatchedToLevelTwoCall():Call(1){}
	virtual ~DispatchedToLevelTwoCall(){}
	bool handle(int rank){return rank == 2;}
};

class DispatchedToLevelThreeCall:public Call {
public:
	DispatchedToLevelThreeCall():Call(1){}
	virtual ~DispatchedToLevelThreeCall(){}
	bool handle(int rank){return rank == 3;}
};

} /* namespace chapterSeven */
#endif /* CALL_H_ */

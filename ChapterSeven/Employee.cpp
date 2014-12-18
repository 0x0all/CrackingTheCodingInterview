/*
 * Employee.cpp
 *
 *  Created on: Dec 17, 2014
 *      Author: ubuntu
 */
#include "Employee.h"
#include "CallHandle.h"

using namespace std;

namespace chapterSeven {

Employee::Employee(int rank, string id):
		_rank(rank), _id(id),_isFree(true){
}

Employee::~Employee() {
}

int Employee::getRank() const{
	return _rank;
}

bool Employee::isFree() const{
	return _isFree;
}

string Employee::getId() const{
	return _id;
}

void Employee::handleCall(Call &call, CallHandle &callHandle){
	_isFree = false;
	if(call.handle(_rank))
		call.HandledBy = getId();
	else
		dispatchCall(call, callHandle);
	callHandle.getNextCall(*this);
}

void Employee::dispatchCall(Call &call, CallHandle &callHandle){
	_isFree = true;
	call.Rank += 1;
	callHandle.dispatchCall(call);
}

} /* namespace chapterSeven */

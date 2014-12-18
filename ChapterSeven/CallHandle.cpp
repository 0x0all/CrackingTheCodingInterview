/*
 * CallHandle.cpp
 *
 *  Created on: Dec 17, 2014
 *      Author: ubuntu
 */

#include <algorithm>
#include "CallHandle.h"

using namespace std;

namespace chapterSeven {

CallHandle::CallHandle(): _freeEmployees(), _pendingCalls(LEVELS){
}

CallHandle::~CallHandle() {
}

void CallHandle::addEmployee(const Employee &employee){
	if(employee.isFree())
		_freeEmployees.push_back(employee);
}

int CallHandle::getNumOfPendingCalls(){
	int sum=0;
	for_each(_pendingCalls.rbegin(), _pendingCalls.rend(),
			[&sum](vector<Call*> &vec)
			{
				sum += vec.size();
			});
	return sum;
}

void CallHandle::dispatchCall(Call &call){
	Employee* emp = getCallHandler(call);
	if(emp != nullptr)
		emp->handleCall(call, *this);
	else
		_pendingCalls[call.Rank-1].push_back(&call);
}

Employee* CallHandle::getCallHandler(const Call &call){
	vector<Employee>::iterator firstWhoCanHandle;
	firstWhoCanHandle = find_if(_freeEmployees.begin(), _freeEmployees.end(),
			[&call](const Employee &employee)->bool
			{
				return call.Rank == employee.getRank();
			}
	);
	return firstWhoCanHandle == _freeEmployees.end() ? nullptr : &(*firstWhoCanHandle);
}

void CallHandle::getNextCall(Employee &employee){
	if( !_pendingCalls[employee.getRank()-1].empty()){
		auto callPtr = _pendingCalls[employee.getRank()].back();
		_pendingCalls[employee.getRank()].pop_back();
		employee.handleCall(*callPtr, *this);
	}
}

} /* namespace chapterSeven */

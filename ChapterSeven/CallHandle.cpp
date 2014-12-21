/*
 * CallHandle.cpp
 *
 *  Created on: Dec 17, 2014
 *      Author: ubuntu
 */

#include <algorithm>
#include <sstream>
#include "CallHandle.h"
#include "Fresher.h"
#include "TechLead.h"
#include "ProductManager.h"

using namespace std;

namespace chapterSeven {


CallHandle::CallHandle(int priorityLevels, int fresher_num, int techLead_num, int producntManager_num)
: _pendingCalls(priorityLevels){
	initFreshers(fresher_num);
	initTechLeads(techLead_num);
	initProductManagers(producntManager_num);
}

CallHandle::~CallHandle() {
}

void CallHandle::initFreshers(int fresher_num) {
	for (int i = 0; i < fresher_num; i++) {
		stringstream sstm;
		sstm << "Fresher_" << i + 1;
		Fresher fresher(sstm.str());
		_freeEmployees.push_back(fresher);
	}
}

void CallHandle::initTechLeads(int techLead_num) {
	for (int i = 0; i < techLead_num; i++) {
		stringstream sstm;
		sstm << "TechLead_" << i + 1;
		TechLead techLead(sstm.str());
		_freeEmployees.push_back(techLead);
	}
}

void CallHandle::initProductManagers(int producntManager_num) {
	for (int i = 0; i < producntManager_num; i++) {
		stringstream sstm;
		sstm << "ProductManager_" << i + 1;
		ProductManager productManager(sstm.str());
		_freeEmployees.push_back(productManager);
	}
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

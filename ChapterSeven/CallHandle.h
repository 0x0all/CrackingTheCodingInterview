/*
 * CallHandle.h
 *
 *  Created on: Dec 17, 2014
 *      Author: ubuntu
 */

#ifndef CALLHANDLE_H_
#define CALLHANDLE_H_
#include <vector>
#include "Employee.h"
#include "Call.h"

using namespace std;

namespace chapterSeven {

class CallHandle {
public:
	CallHandle(int priorityLevels, int fresher_num, int techLead_num, int producntManager_num);
	virtual ~CallHandle();
	void addEmployee(const Employee &employee);
	void dispatchCall(Call &call);
	Employee* getCallHandler(const Call &call);
	void getNextCall(Employee &employee);
	int getNumOfPendingCalls();
private:
	vector<Employee> _freeEmployees;
	vector<vector<Call*>>  _pendingCalls;

	void initFreshers(int fresher_num);
	void initTechLeads(int techLead_num);
	void initProductManagers(int producntManager_num);
};

} /* namespace chapterSeven */
#endif /* CALLHANDLE_H_ */

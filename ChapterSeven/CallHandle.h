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
	CallHandle();
	virtual ~CallHandle();
	static const int LEVELS = 3;
	void addEmployee(const Employee &employee);
	void dispatchCall(Call &call);
	Employee* getCallHandler(const Call &call);
	void getNextCall(Employee &employee);
	int getNumOfPendingCalls();
private:
	vector<Employee> _freeEmployees;
	vector<vector<Call*>>  _pendingCalls;
};

} /* namespace chapterSeven */
#endif /* CALLHANDLE_H_ */

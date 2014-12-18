/*
 * Employee.h
 *
 *  Created on: Dec 17, 2014
 *      Author: ubuntu
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string>
#include "Call.h"

using namespace std;

namespace chapterSeven {

class CallHandle;

class Employee {
public:
	Employee(int rank, string id);
	virtual ~Employee();
	int getRank() const;
	bool isFree() const;
	string getId() const;
	void handleCall(Call &call, CallHandle &callHandle);
	void dispatchCall(Call &call, CallHandle &_callHandle);
private:
	int _rank;
	string _id;
	bool _isFree;

};

} /* namespace chapterSeven */
#endif /* EMPLOYEE_H_ */

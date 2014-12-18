/*
 * Fresher.h
 *
 *  Created on: Dec 17, 2014
 *      Author: ubuntu
 */

#ifndef FRESHER_H_
#define FRESHER_H_
#include "Employee.h"

using namespace std;

namespace chapterSeven {

class Fresher:public Employee {
public:
	Fresher(string id):Employee(1, id){}
	virtual ~Fresher(){}
};

} /* namespace chapterSeven */
#endif /* FRESHER_H_ */

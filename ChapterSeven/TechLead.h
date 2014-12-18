/*
 * TechLead.h
 *
 *  Created on: Dec 17, 2014
 *      Author: ubuntu
 */

#ifndef TECHLEAD_H_
#define TECHLEAD_H_
#include "Employee.h"

namespace chapterSeven {

class TechLead: public Employee {
public:
	TechLead(string id):Employee(2, id){}
	virtual ~TechLead(){}
};

} /* namespace chapterSeven */
#endif /* TECHLEAD_H_ */

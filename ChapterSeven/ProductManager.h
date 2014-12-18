/*
 * ProductManager.h
 *
 *  Created on: Dec 17, 2014
 *      Author: ubuntu
 */

#ifndef PRODUCTMANAGER_H_
#define PRODUCTMANAGER_H_
#include "Employee.h"

namespace chapterSeven {

class ProductManager:public Employee {
public:
	ProductManager(string id):Employee(3, id){}
	virtual ~ProductManager(){}
};

} /* namespace chapterSeven */
#endif /* PRODUCTMANAGER_H_ */

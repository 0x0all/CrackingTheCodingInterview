/*
 * RuntimeException.h
 *
 *  Created on: Nov 24, 2014
 *      Author: ubuntu
 */

#ifndef RUNTIMEEXCEPTION_H_
#define RUNTIMEEXCEPTION_H_

#include <exception>

namespace chapterThree {

class RuntimeException: public std::exception {
public:
	RuntimeException();
	virtual ~RuntimeException();
};

} /* namespace twotwo */
#endif /* RUNTIMEEXCEPTION_H_ */

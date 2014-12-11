/*
 * AbstractTree.h
 *
 *  Created on: Nov 25, 2014
 *      Author: ubuntu
 */

#ifndef ABSTRACTTREE_H_
#define ABSTRACTTREE_H_
#include <vector>
#include <memory>
#include "Node.h"

using namespace std;

namespace chapterFour {

template<class T>
class AbstractTree {
public:
	AbstractTree(){}
	virtual ~AbstractTree(){}
	virtual void addNode(T value)=0;
};

} /* namespace four */
#endif /* ABSTRACTTREE_H_ */

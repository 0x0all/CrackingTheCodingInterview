/*
 * Node.h
 *
 *  Created on: Dec 2, 2014
 *      Author: ubuntu
 */

#ifndef NODE_H_
#define NODE_H_

namespace chapterFour {

template<class T>
struct Node {
	Node(){}
	Node(T val):value(val){}
	virtual ~Node(){}
	T value;
};

} /* namespace four */
#endif /* NODE_H_ */

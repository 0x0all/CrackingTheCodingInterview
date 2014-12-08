/*
 * GraphNode.h
 *
 *  Created on: Dec 2, 2014
 *      Author: ubuntu
 */

#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_
#include <vector>
#include <memory>
#include <iostream>
#include "Node.h"

using namespace std;

namespace chapterFour {

template<class T>
struct GraphNode : Node<T>{

	GraphNode(T val): Node<T>(val),adjacent(0){}

	virtual ~GraphNode(){}

	bool hasAdjacent(){
		return !adjacent.empty();
	}

	vector<shared_ptr<GraphNode<T>>> adjacent;
};

} /* namespace four */
#endif /* GRAPHNODE_H_ */

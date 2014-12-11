/*
 * TreeNode.h
 *
 *  Created on: Nov 25, 2014
 *      Author: ubuntu
 */

#ifndef TREENODE_H_
#define TREENODE_H_
#include <sstream>
#include <string>
#include <iostream>
#include <memory>
#include "Node.h"

using namespace std;

namespace chapterFour {

template<class T>
struct TreeNode : Node<T> {

	TreeNode<T>* leftChild;

	TreeNode<T>* rightChild;

	TreeNode<T>* parent;

	TreeNode() : leftChild(nullptr), rightChild(nullptr), parent(nullptr){}

	TreeNode(T val): Node<T>(val), leftChild(nullptr), rightChild(nullptr), parent(nullptr){}

	TreeNode(T val, TreeNode<T>* par): Node<T>(val), leftChild(nullptr), rightChild(nullptr), parent(par){}

	virtual ~TreeNode(){}

	bool isLeaf(){
		return leftChild == nullptr && rightChild == nullptr;
	}

	string toString(){
		stringstream stream;
		stream << this->value;
		return stream.str();
	}

	string toStringWithChildren(){
		stringstream stream;
		string left  = leftChild  == nullptr ? "null" : leftChild->toString();
		string right = rightChild == nullptr ? "null" : rightChild->toString();
		stream << this->toString() << " L: " << left << " R: " << right;
		return stream.str();
	}

};

} /* namespace four */
#endif /* TREENODE_H_ */

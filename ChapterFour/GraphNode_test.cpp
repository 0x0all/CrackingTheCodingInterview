/*
 * GraphNode_test.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: ubuntu
 */

#include <gtest/gtest.h>
#include "GraphNode.h"

using namespace std;

namespace chapterFour {

TEST(GraphNodeTest, Creation){
	GraphNode<int> node(1);
	ASSERT_EQ(1, node.value);
	ASSERT_FALSE(node.hasAdjacent());
}

TEST(GraphNodeTest, AddAdjacent){
	GraphNode<int> node(1);
	GraphNode<int> two(2);
	GraphNode<int> three(3);
	node.adjacent.push_back(&two);
	node.adjacent.push_back(&three);
	ASSERT_EQ(2, node.adjacent[0]->value);
	ASSERT_EQ(3, node.adjacent[1]->value);
}

} /* namespace four */

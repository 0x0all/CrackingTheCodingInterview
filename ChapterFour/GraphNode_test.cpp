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
	node.adjacent.push_back(shared_ptr<GraphNode<int>>(new GraphNode<int>(2)));
	node.adjacent.push_back(shared_ptr<GraphNode<int>>(new GraphNode<int>(3)));
	ASSERT_EQ(2, node.adjacent[0]->value);
	ASSERT_EQ(3, node.adjacent[1]->value);
}

TEST(GraphNodeTest, EmplaceAdjacent){
	GraphNode<int> node(1);
	node.adjacent.emplace_back(new GraphNode<int>(2));
	node.adjacent.emplace_back(new GraphNode<int>(3));
	ASSERT_EQ(2, node.adjacent[0]->value);
	ASSERT_EQ(3, node.adjacent[1]->value);
}

TEST(GraphNodeTest, EmplaceMakeShared){
	GraphNode<int> node(1);
	node.adjacent.emplace_back(make_shared<GraphNode<int>>(2));
	node.adjacent.emplace_back(make_shared<GraphNode<int>>(3));
	ASSERT_EQ(2, node.adjacent[0]->value);
	ASSERT_EQ(3, node.adjacent[1]->value);
}



} /* namespace four */

/*
 * Graph_test.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: ubuntu
 */

#include <gtest/gtest.h>
#include "Graph.h"

namespace chapterFour {

TEST(GraphTest, Creation){
	Graph<int> graph;
	graph.addNode(1);
	graph.addNode(2);
	std::vector<std::shared_ptr<GraphNode<int>>> nodes = graph.getNodes();
	ASSERT_EQ(1, nodes[0]->value);
	ASSERT_EQ(2, nodes[1]->value);
}

TEST(GraphTest, PathExistSameNode)
{
	std::shared_ptr <GraphNode<int>> one = std::make_shared < GraphNode<int>> (1);
	std::shared_ptr <GraphNode<int>> two = std::make_shared < GraphNode<int>> (2);
	std::shared_ptr <GraphNode<int>> three = std::make_shared < GraphNode<int>> (3);
	std::shared_ptr <GraphNode<int>> four = std::make_shared < GraphNode<int>> (4);
	one->adjacent.push_back(two);
	one->adjacent.push_back(three);
	two->adjacent.push_back(three);
	three->adjacent.push_back(four);
	four->adjacent.push_back(one);
	Graph<int> graph;
	graph.addNode(one);
	graph.addNode(two);
	graph.addNode(three);
	graph.addNode(four);

	ASSERT_TRUE(Graph<int>::pathExist(graph, one, one));
}

TEST(GraphTest, PathExist)
{
	std::shared_ptr <GraphNode<int>> one = std::make_shared < GraphNode<int>> (1);
	std::shared_ptr <GraphNode<int>> two = std::make_shared < GraphNode<int>> (2);
	std::shared_ptr <GraphNode<int>> three = std::make_shared < GraphNode<int>> (3);
	std::shared_ptr <GraphNode<int>> four = std::make_shared < GraphNode<int>> (4);
	one->adjacent.push_back(two);
	one->adjacent.push_back(three);
	two->adjacent.push_back(three);
	three->adjacent.push_back(four);
	four->adjacent.push_back(one);
	Graph<int> graph;
	graph.addNode(one);
	graph.addNode(two);
	graph.addNode(three);
	graph.addNode(four);

	ASSERT_TRUE(Graph<int>::pathExist(graph, one, two));
	ASSERT_TRUE(Graph<int>::pathExist(graph, one, three));
	ASSERT_TRUE(Graph<int>::pathExist(graph, one, four));
	ASSERT_TRUE(Graph<int>::pathExist(graph, two, four));
}

TEST(GraphTest, PathNotExist)
{
	std::shared_ptr <GraphNode<int>> one = std::make_shared < GraphNode<int>> (1);
	std::shared_ptr <GraphNode<int>> two = std::make_shared < GraphNode<int>> (2);
	std::shared_ptr <GraphNode<int>> three = std::make_shared < GraphNode<int>> (3);
	std::shared_ptr <GraphNode<int>> four = std::make_shared < GraphNode<int>> (4);
	std::shared_ptr <GraphNode<int>> five = std::make_shared < GraphNode<int>> (5);
	one->adjacent.push_back(two);
	one->adjacent.push_back(three);
	two->adjacent.push_back(three);
	three->adjacent.push_back(four);
	four->adjacent.push_back(one);
	Graph<int> graph;
	graph.addNode(one);
	graph.addNode(two);
	graph.addNode(three);
	graph.addNode(four);
	graph.addNode(five);

	ASSERT_FALSE(Graph<int>::pathExist(graph, one, five));
	ASSERT_FALSE(Graph<int>::pathExist(graph, two, five));
	ASSERT_FALSE(Graph<int>::pathExist(graph, three, five));
	ASSERT_FALSE(Graph<int>::pathExist(graph, four, five));
}

} /* namespace four */

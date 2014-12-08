/*
 * Graph_test.cpp
 *
 *  Created on: Dec 2, 2014
 *      Author: ubuntu
 */

#include <gtest/gtest.h>
#include "Graph.h"

using namespace std;

namespace chapterFour {

TEST(GraphTest, Creation){
	Graph<int> graph;
	graph.addNode(1);
	graph.addNode(2);
	vector<shared_ptr<GraphNode<int>>> nodes = graph.getNodes();
	ASSERT_EQ(1, nodes[0]->value);
	ASSERT_EQ(2, nodes[1]->value);
}

TEST(GraphTest, PathExistSameNode)
{
	shared_ptr <GraphNode<int>> one = make_shared < GraphNode<int>> (1);
	shared_ptr <GraphNode<int>> two = make_shared < GraphNode<int>> (2);
	shared_ptr <GraphNode<int>> three = make_shared < GraphNode<int>> (3);
	shared_ptr <GraphNode<int>> four = make_shared < GraphNode<int>> (4);
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
	shared_ptr <GraphNode<int>> one = make_shared < GraphNode<int>> (1);
	shared_ptr <GraphNode<int>> two = make_shared < GraphNode<int>> (2);
	shared_ptr <GraphNode<int>> three = make_shared < GraphNode<int>> (3);
	shared_ptr <GraphNode<int>> four = make_shared < GraphNode<int>> (4);
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
	shared_ptr <GraphNode<int>> one = make_shared < GraphNode<int>> (1);
	shared_ptr <GraphNode<int>> two = make_shared < GraphNode<int>> (2);
	shared_ptr <GraphNode<int>> three = make_shared < GraphNode<int>> (3);
	shared_ptr <GraphNode<int>> four = make_shared < GraphNode<int>> (4);
	shared_ptr <GraphNode<int>> five = make_shared < GraphNode<int>> (5);
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

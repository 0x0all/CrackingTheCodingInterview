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

class GraphTest: public testing::Test {
public:
	GraphTest() :
			_graph(nullptr), _one(nullptr), _two(nullptr), _three(nullptr), _four(nullptr) {
	}
protected:
	virtual void SetUp() {
		_graph.reset(new Graph<int>());
		_one   = _graph->addNode(1);
		_two   = _graph->addNode(2);
		_three = _graph->addNode(3);
		_four  = _graph->addNode(4);
		_one->adjacent.push_back(_two);
		_one->adjacent.push_back(_three);
		_two->adjacent.push_back(_three);
		_three->adjacent.push_back(_four);
		_four->adjacent.push_back(_one);
	}

	unique_ptr<Graph<int>> _graph;
	GraphNode<int>* _one;
	GraphNode<int>* _two;
	GraphNode<int>* _three;
	GraphNode<int>* _four;
};

TEST_F(GraphTest, Creation) {
	Graph<int> graph;
	graph.addNode(1);
	graph.addNode(2);
	const vector<GraphNode<int>*> nodes = graph.getNodes();
	ASSERT_EQ(1, nodes[0]->value);
	ASSERT_EQ(2, nodes[1]->value);
}

TEST_F(GraphTest, PathExistSameNode) {
	ASSERT_TRUE(Graph<int>::pathExist(*_graph, *_one, *_one));
}

TEST_F(GraphTest, PathExist) {
	ASSERT_TRUE(Graph<int>::pathExist(*_graph, *_one, *_two));
	ASSERT_TRUE(Graph<int>::pathExist(*_graph, *_one, *_three));
	ASSERT_TRUE(Graph<int>::pathExist(*_graph, *_one, *_four));
	ASSERT_TRUE(Graph<int>::pathExist(*_graph, *_two, *_four));
}

TEST_F(GraphTest, PathNotExist) {
	GraphNode<int>* five = _graph->addNode(5);

	ASSERT_FALSE(Graph<int>::pathExist(*_graph, *_one,   *five));
	ASSERT_FALSE(Graph<int>::pathExist(*_graph, *_two,   *five));
	ASSERT_FALSE(Graph<int>::pathExist(*_graph, *_three, *five));
	ASSERT_FALSE(Graph<int>::pathExist(*_graph, *_four,  *five));
}

} /* namespace four */

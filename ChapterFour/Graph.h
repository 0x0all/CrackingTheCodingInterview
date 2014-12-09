/*
 * Graph.h
 *
 *  Created on: Dec 2, 2014
 *      Author: ubuntu
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <memory>
#include <map>
#include <queue>
#include "GraphNode.h"

using namespace std;

namespace chapterFour {

enum class Tag {Unvisited, Visited, Discovered};

template<class T>
class Graph {
public:
	Graph(){}
	virtual ~Graph(){}
	void addNode(shared_ptr<GraphNode<T>> node){
		nodes.push_back(node);
	}

	void addNode(T val){
		nodes.emplace_back(make_shared<GraphNode<T>>(val));
	}

	const vector<shared_ptr<GraphNode<T>>> getNodes() const {
		return nodes;
	}

	/*
	4.2:Given a directed graph, design an algorithm to find out whether there is a route be-
	tween two nodes.
	*/
	static bool pathExist(const Graph<T> &graph, const shared_ptr<GraphNode<T>> &source, const shared_ptr<GraphNode<T>> &destination){
		if(source == destination)
			return true;
		map<shared_ptr<GraphNode<T>>, Tag> visitationMap = initVisitationMap(graph);
		return searchBfsForPath(source, destination, visitationMap);
	}

private:
	static map<shared_ptr<GraphNode<T>>, Tag> initVisitationMap(const Graph<T> &graph){
		map<shared_ptr<GraphNode<T>>, Tag> visitationMap;
		for(auto node : graph.getNodes())
			visitationMap.emplace(node, Tag::Unvisited);
		return visitationMap;
	}

	static bool searchBfsForPath(const shared_ptr<GraphNode<T>> &source, const shared_ptr<GraphNode<T>> &destination, map<shared_ptr<GraphNode<T>>, Tag> &visitationMap){
		queue<shared_ptr<GraphNode<T>>> queue;
		queue.push(source);

		while(!queue.empty()){
			auto top = queue.front();
			if(destination == top)
				return true;
			else{
				queue.pop();
				pushUnvisitedNodesToQueue(queue, top, visitationMap);
			}
			visitationMap[top] = Tag::Visited;
		}
		return false;
	}

	static void pushUnvisitedNodesToQueue(queue<shared_ptr<GraphNode<T>>> &queue, const shared_ptr<GraphNode<T>> &node, map<shared_ptr<GraphNode<T>>, Tag> &visitationMap){
		for(auto adjNode : node->adjacent){
			if(visitationMap[adjNode] == Tag::Unvisited){
				queue.push(adjNode);
				visitationMap[adjNode] = Tag::Discovered;
			}
		}
	}

	vector<shared_ptr<GraphNode<T>>> nodes;
};

} /* namespace four */
#endif /* GRAPH_H_ */

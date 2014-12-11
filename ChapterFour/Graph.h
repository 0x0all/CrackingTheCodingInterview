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

	GraphNode<T>* addNode(const GraphNode<T> &node){
		_nodes.emplace_back(new GraphNode<T>(node));
		return _nodes.back().get();
	}

	GraphNode<T>* addNode(T val){
		_nodes.emplace_back(new GraphNode<T>(val));
		return _nodes.back().get();
	}

	const vector<GraphNode<T>*> getNodes() const {
		vector<GraphNode<T>*> result;
		for (unsigned i=0; i<_nodes.size(); i++)
			result.push_back(_nodes.at(i).get());
		return result;
	}


//	4.2:Given a directed graph, design an algorithm to find out whether there is a route be-
//	tween two nodes.
	static bool pathExist(const Graph<T> &graph, const GraphNode<T> &source, const GraphNode<T> &destination){
		if(&source == &destination)
			return true;
		map<GraphNode<T>*, Tag> visitationMap = initVisitationMap(graph);
		return searchBfsForPath(source, destination, visitationMap);
	}

private:

	static map<GraphNode<T>*, Tag> initVisitationMap(const Graph<T> &graph){
		map<GraphNode<T>*, Tag> visitationMap;
		for(auto node : graph.getNodes())
			visitationMap.emplace(node, Tag::Unvisited);
		return visitationMap;
	}

	static bool searchBfsForPath(const GraphNode<T> &source, const GraphNode<T> &destination, map<GraphNode<T>*, Tag> &visitationMap){
		queue<GraphNode<T>*> queue;
		queue.push(const_cast<GraphNode<T>*>(&source));

		while(!queue.empty()){
			auto top = queue.front();
			if(&destination == top)
				return true;
			else{
				queue.pop();
				pushUnvisitedNodesToQueue(queue, *top, visitationMap);
			}
			visitationMap[top] = Tag::Visited;
		}
		return false;
	}

	static void pushUnvisitedNodesToQueue(queue<GraphNode<T>*> &queue, const GraphNode<T> &node, map<GraphNode<T>*, Tag> &visitationMap){
		for(auto adjNode : node.adjacent){
			if(visitationMap[adjNode] == Tag::Unvisited){
				queue.push(adjNode);
				visitationMap[adjNode] = Tag::Discovered;
			}
		}
	}

	vector<unique_ptr<GraphNode<T>>> _nodes;
};

} /* namespace four */
#endif /* GRAPH_H_ */

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

namespace chapterFour {

template<class T>
class Graph {
public:
	Graph(){}
	virtual ~Graph(){}
	void addNode(std::shared_ptr<GraphNode<T>> node){
		nodes.push_back(node);
	}

	void addNode(T val){
		nodes.emplace_back(std::make_shared<GraphNode<T>>(val));
	}

	const std::vector<std::shared_ptr<GraphNode<T>>> getNodes() const {
		return nodes;
	}

	static bool pathExist(const Graph<T> &graph, const std::shared_ptr<GraphNode<T>> &source, const std::shared_ptr<GraphNode<T>> &dest){
		if(source == dest)
			return true;

		enum class Tag {Unvisited, Visited, Discovered};

		std::map<std::shared_ptr<GraphNode<T>>, Tag> visitationMap;
		for(auto node : graph.getNodes())
			visitationMap.emplace(node, Tag::Unvisited);

		std::queue<std::shared_ptr<GraphNode<T>>> queue;
		queue.push(source);

		while(!queue.empty()){
			auto top = queue.front();
			queue.pop();
			if(top == dest)
				return true;
			else{
				for(auto adjNode : top->adjacent){
					if(visitationMap[adjNode] == Tag::Unvisited){
						queue.push(adjNode);
						visitationMap[adjNode] = Tag::Discovered;
					}
				}
			}
			visitationMap[top] = Tag::Visited;
		}
		return false;
	}

private:
	std::vector<std::shared_ptr<GraphNode<T>>> nodes;
};

} /* namespace four */
#endif /* GRAPH_H_ */

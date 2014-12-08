/*
 * BinaryTree.h
 *
 *  Created on: Nov 25, 2014
 *      Author: ubuntu
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <vector>
#include <queue>
#include <map>
#include "AbstractTree.h"
#include "TreeNode.h"

using namespace std;

namespace chapterFour {

template<class T>
using sptr_node = shared_ptr<TreeNode<T>>;

template<class T>
using vector_of_sptr_nodes = vector<shared_ptr<TreeNode<T>>>;

template<class T>
using queue_of_sptr_nodes = queue<shared_ptr<TreeNode<T>>>;

template<class T>
class BinaryTree: public AbstractTree<T> {
public:
	BinaryTree(T rootValue):_root(new TreeNode<T>(rootValue)){}

	BinaryTree(const vector<T> &values){
		_root = createFromArray(values, 0, values.size() -1);
	}

	virtual ~BinaryTree(){}

	static vector<vector<shared_ptr<TreeNode<int>>>> findAllPathsToSum(const BinaryTree<int> &tree, int sum){
		vector<vector<shared_ptr<TreeNode<int>>>> result;
		shared_ptr<TreeNode<int> > root = tree.getRoot();
		if(root == nullptr) return result;
		int level = 0;
		vector<shared_ptr<TreeNode<int>>> buffer;
		searchAllPathsForSum(root, sum, buffer, level,result);
		return result;
	}

	static bool containsSubTree(const BinaryTree<T> &bigTree, const BinaryTree<T> &smallTree){
		shared_ptr<TreeNode<T> > smallRoot = smallTree.getRoot();
		if(smallRoot == nullptr) return true;
		else return subTree(bigTree.getRoot(), smallRoot);
	}

	static sptr_node<T> commonAncestor(const sptr_node<T> &root, const sptr_node<T> &first, const sptr_node<T> &second){
		if(covers(root->leftChild, first) && covers(root->leftChild, second)){
			return commonAncestor(root->leftChild, first, second);
		}
		if(covers(root->rightChild, first) && covers(root->rightChild, second)){
			return commonAncestor(root->rightChild, first, second);
		}
		return root;
	}

	map<int, vector_of_sptr_nodes<T>> getNodesPerLevel() const{
			map<int, vector_of_sptr_nodes<T>> result;
			if(_root == nullptr)
				return result;
			int levelNum = -1;
			bool levelIndicatorPoped = false;
			sptr_node<T> levelIndicator = make_shared<TreeNode<T>>();

			queue_of_sptr_nodes<T> queue;
			queue.push(levelIndicator);
			queue.push(_root);

			while(!queue.empty()){
				sptr_node<T> front = queue.front();
				queue.pop();
				if(front == levelIndicator && !queue.empty()){
					levelIndicatorPoped = true;
					++levelNum;
					front = queue.front();
					queue.pop();
				}
				result[levelNum].push_back(front);

				if(levelIndicatorPoped && (front->leftChild != nullptr || front->rightChild != nullptr)){
					queue.push(levelIndicator);
					levelIndicatorPoped = false;
				}

				if(front->leftChild != nullptr){
					queue.push(front->leftChild);
				}
				if(front->rightChild != nullptr){
					queue.push(front->rightChild);
				}

			}
			return result;
		}

	bool isBalancedRecursive() const{
		return maxDepth(_root) - minDepth(_root) <= 1;
	}

	bool isBalanced() const{
		int firstLeafLevel=-1;
		queue<pair<sptr_node<T>,int>> queue;
		queue.emplace(_root, 0);
		while(!queue.empty()){
			pair<sptr_node<T>, int> top = queue.front();
			queue.pop();
			if(!top.first->isLeaf()){
				if(top.first->leftChild != nullptr)
					queue.emplace(top.first->leftChild,  top.second+1);
				if(top.first->rightChild != nullptr)
					queue.emplace(top.first->rightChild, top.second+1);
			}
			else{
				if(firstLeafLevel < 0)
					firstLeafLevel = top.second;
				else if(top.second - firstLeafLevel > 1)
					return false;
			}
		}
		return true;
	}

	vector<T> levelOrderTraversalValues() const{
		vector<T> result;
		queue_of_sptr_nodes<T> queue;
		queue.push(_root);
		levelOrder(queue, result);
		return result;
	}

	vector<T> inOrderTraversalValues() const{
		vector<T> result;
		inOrder(_root, result);
		return result;
	}

	vector<T> preOrderTraversalValues() const{
		vector<T> result;
		preOrder(_root, result);
		return result;
	}

	vector<T> postOrderTraversalValues() const{
		vector<T> result;
		postOrder(_root, result);
		return result;
	}

	sptr_node<T> getRoot() const {
		return _root;
	}

	sptr_node<T> inOrderNext(sptr_node<T> node) const{
			if(node->rightChild != nullptr)
				node = leftMostChild(node->rightChild);
			else{
				sptr_node<T> parent;
				while((parent = node->parent) != nullptr){
					if(parent->leftChild == node){
						break;
					}
					node = parent;
				}
				node = parent;
			}
			return node;
		}

	void addNode(T value){
		this->addNodeToRoot(_root, value);
	}

	void addNodeWithLinkToParent(T value){
		this->addNodeToRootWithParent(_root, value, _root);
	}

private:
	static void searchAllPathsForSum(const shared_ptr<TreeNode<int>> &root, int sum, vector<shared_ptr<TreeNode<int> > > &buffer, int level, vector<vector<shared_ptr<TreeNode<int> >>> &result){
		if(root == nullptr) return;
		int temp = sum;
		buffer.push_back(root);
		for(int i = level; i > -1; --i){
			temp -= buffer[i]->value;
			if(temp == 0 ){
				vector<shared_ptr<TreeNode<int>>> path;
				for(int j = i; j <=level;j++){
					path.push_back(buffer[j]);
				}
				result.push_back(path);
			}
		}
		vector<shared_ptr<TreeNode<int>>> leftBuffer(buffer);
		vector<shared_ptr<TreeNode<int>>> rightBuffer(buffer);
		searchAllPathsForSum(root->leftChild, sum, leftBuffer, level +1, result);
		searchAllPathsForSum(root->rightChild, sum, rightBuffer, level +1, result);
	}

	static bool subTree(const sptr_node<T> &bigRoot, const sptr_node<T> &smallRoot){
		if(bigRoot == nullptr){
			return false;
		}
		if(bigRoot->value == smallRoot->value){
			if(match(bigRoot, smallRoot)) return true;
		}
		return subTree(bigRoot->leftChild, smallRoot) || subTree(bigRoot->rightChild, smallRoot);
	}

	static bool match(const sptr_node<T> &bigRoot, const sptr_node<T> &smallRoot){
		if(bigRoot == nullptr && smallRoot == nullptr)
			return true;
		if(bigRoot == nullptr || smallRoot == nullptr)
			return false;
		if(bigRoot->value != smallRoot->value)
			return false;
		return match(bigRoot->leftChild, smallRoot->leftChild) && match(bigRoot->rightChild, smallRoot->rightChild);
	}

	static bool covers(const sptr_node<T> &root, const sptr_node<T> &target){
		if(root == nullptr) return false;
		if(root == target) return true;
		return covers(root->leftChild, target) || covers(root->rightChild, target);
	}

	static sptr_node<T> leftMostChild(sptr_node<T> node){
		while(node->leftChild != nullptr)
			node = node->leftChild;
		return node;
	}

	sptr_node<T> createFromArray(const vector<T> &values, int start, int end){
		if(start > end || end < 0)
			return nullptr;
		int middleIndex = (start + end)/2;
		sptr_node<T> middle = make_shared<TreeNode<T>>(values[middleIndex]);
		middle->leftChild = createFromArray(values, start, middleIndex-1);
		middle->rightChild = createFromArray(values, middleIndex+1, end);

		return middle;
	}

	static int maxDepth(const sptr_node<T> &root){
		if(root == nullptr)
			return 0;
		return 1 + max(maxDepth(root->leftChild), maxDepth(root->rightChild));
	}

	static int minDepth(const sptr_node<T> &root){
		if(root == nullptr)
			return 0;
		return 1 + min(minDepth(root->leftChild), minDepth(root->rightChild));
	}

	void levelOrder(queue_of_sptr_nodes<T> &queue, vector<T> &vec) const{
		while(!queue.empty()){
			sptr_node<T> top = queue.front();
			queue.pop();
			vec.push_back(top->value);
			if(top->leftChild)
				queue.push(top->leftChild);
			if(top->rightChild)
				queue.push(top->rightChild);
		}
	}

	void postOrder(const sptr_node<T> &node, vector<T> &vec) const{
		if(node){
			postOrder(node->leftChild, vec);
			postOrder(node->rightChild, vec);
			vec.push_back( node->value);
		}
	}

	void preOrder(const sptr_node<T> &node, vector<T> &vec) const{
		if(node){
			vec.push_back( node->value);
			preOrder(node->leftChild, vec);
			preOrder(node->rightChild, vec);
		}
	}

	void inOrder(const sptr_node<T> &node, vector<T> &vec) const{
		if(node){
			inOrder(node->leftChild, vec);
			vec.push_back( node->value);
			inOrder(node->rightChild, vec);
		}
	}

	void addNodeToRoot(const sptr_node<T> &curRoot, T value){
		if(value >= curRoot->value){
			if(curRoot->rightChild != nullptr)
				this->addNodeToRoot(curRoot->rightChild, value);
			else
				curRoot->rightChild.reset(new TreeNode<T>(value));
		}
		else{
			if(curRoot->leftChild!= nullptr)
				this->addNodeToRoot(curRoot->leftChild, value);
			else
				curRoot->leftChild.reset(new TreeNode<T>(value));
		}
	}

	void addNodeToRootWithParent(const sptr_node<T> &curRoot, T value, const sptr_node<T> &curParent){
			if(value >= curRoot->value){
				if(curRoot->rightChild != nullptr)
					this->addNodeToRootWithParent(curRoot->rightChild, value, curRoot->rightChild);
				else
					curRoot->rightChild.reset(new TreeNode<T>(value, curParent));
			}
			else{
				if(curRoot->leftChild!= nullptr)
					this->addNodeToRootWithParent(curRoot->leftChild, value, curRoot->leftChild);
				else
					curRoot->leftChild.reset(new TreeNode<T>(value, curParent));
			}
	}

	sptr_node<T> _root;
};

} /* namespace four */
#endif /* BINARYTREE_H_ */

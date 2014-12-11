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
class BinaryTree: public AbstractTree<T> {
public:
	BinaryTree(T rootValue) {
		_nodes.emplace_back(new TreeNode<T>(rootValue));
		_root = _nodes.front().get();
	}

//	4.3:Given a sorted (increasing order) array, write an algorithm to create a binary tree with
//	minimal height
	BinaryTree(const vector<T> &values) {
		_root = createFromArray(values, 0, values.size() - 1);
	}

	virtual ~BinaryTree() {
	}

	const TreeNode<T>* getRootPtr() const {
		return _root;
	}

	void addNode(T value) {
		_nodes.emplace_back(new TreeNode<T>(value));
		this->addNodeToRoot(*_root, *(_nodes.back()));
	}

	void addNodeWithLinkToParent(T value) {
		_nodes.emplace_back(new TreeNode<T>(value));
		this->addNodeToRootWithParent(*_root, *(_nodes.back()), *_root);
	}

	vector<T> levelOrderTraversalValues() const {
		vector<T> result;
		queue<TreeNode<T>*> queue;
		queue.push(_root);
		levelOrder(queue, result);
		return result;
	}

	vector<T> inOrderTraversalValues() const {
		vector<T> result;
		inOrder(_root, result);
		return result;
	}

	vector<T> preOrderTraversalValues() const {
		vector<T> result;
		preOrder(_root, result);
		return result;
	}

	vector<T> postOrderTraversalValues() const {
		vector<T> result;
		postOrder(_root, result);
		return result;
	}

	//	4.1:Implement a function to check if a tree is balanced. For the purposes of this question,
	//	a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
	//	from the root by more than one.
	bool isBalanced() const {
		int firstLeafLevel = -1;
		queue<pair<TreeNode<T>*, int>> queue;
		queue.emplace(_root, 0);
		while (!queue.empty()) {
			auto top = queue.front();
			queue.pop();
			if (!top.first->isLeaf()) {
				if (top.first->leftChild != nullptr)
					queue.emplace(top.first->leftChild, top.second + 1);
				if (top.first->rightChild != nullptr)
					queue.emplace(top.first->rightChild, top.second + 1);
			} else {
				if (firstLeafLevel < 0)
					firstLeafLevel = top.second;
				else if (top.second - firstLeafLevel > 1)
					return false;
			}
		}
		return true;
	}

	//	4.1:Implement a function to check if a tree is balanced. For the purposes of this question,
	//	a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
	//	from the root by more than one.
	bool isBalancedRecursive() const {
		return maxDepth(_root) - minDepth(_root) <= 1;
	}

	//	4.4:Given a binary search tree, design an algorithm which creates a linked list of all the
	//	nodes at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists).
	map<int, vector<TreeNode<T>*>> getNodesPerLevel() const {
		map<int, vector<TreeNode<T>*>> result;
		if (_root == nullptr)
			return result;
		int levelNum = -1;
		bool levelIndicatorPoped = false;
		auto levelIndicator = TreeNode<T>();

		queue<TreeNode<T>*> queue;
		queue.push(&levelIndicator);
		queue.push(_root);

		while (!queue.empty()) {
			auto front = queue.front();
			queue.pop();
			if (front == &levelIndicator && !queue.empty()) {
				levelIndicatorPoped = true;
				++levelNum;
				front = queue.front();
				queue.pop();
			}
			result[levelNum].push_back(front);

			if (levelIndicatorPoped
					&& (front->leftChild != nullptr
							|| front->rightChild != nullptr)) {
				queue.push(&levelIndicator);
				levelIndicatorPoped = false;
			}

			if (front->leftChild != nullptr) {
				queue.push(front->leftChild);
			}
			if (front->rightChild != nullptr) {
				queue.push(front->rightChild);
			}

		}
		return result;
	}

	//	4.5:Write an algorithm to find the ‘next’ node (i.e., in-order successor) of a given node in
	//	a binary search tree where each node has a link to its parent.
	const TreeNode<T> *inOrderNext(const TreeNode<T> &node) const {
		const TreeNode<T> *next = &node;
		if (next->rightChild != nullptr)
			next = leftMostChild(*next->rightChild);
		else {
			TreeNode<T> *parent;
			while ((parent = next->parent) != nullptr) {
				if (parent->leftChild == next) {
					break;
				}
				next = parent;
			}
			next = parent;
		}
		return next;
	}

	//	4.6:Design an algorithm and write code to find the first common ancestor of two nodes
	//	in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
	//	necessarily a binary search tree.
	static const TreeNode<T> *commonAncestor(const TreeNode<T> &root,
			const TreeNode<T> &first, const TreeNode<T> &second) {
		if (covers(root.leftChild, &first) && covers(root.leftChild, &second)) {
			return commonAncestor(*root.leftChild, first, second);
		}
		if (covers(root.rightChild, &first)
				&& covers(root.rightChild, &second)) {
			return commonAncestor(*root.rightChild, first, second);
		}
		return &root;
	}

	//	4.7:You have two very large binary trees: T1, with millions of nodes, and T2, with hun-
	//	dreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.
	static bool containsSubTree(const BinaryTree<T> &bigTree,
			const BinaryTree<T> &smallTree) {
		const TreeNode<T> *smallRoot = smallTree.getRootPtr();
		if (smallRoot == nullptr)
			return true;
		else
			return subTree(bigTree.getRootPtr(), smallRoot);
	}

	//	4.8:You are given a binary tree in which each node contains a value. Design an algorithm
	//	to print all paths which sum up to that value. Note that it can be any path in the tree
	//	- it does not have to start at the root.
	static vector<vector<TreeNode<int>*>> findAllPathsToSum(
			const BinaryTree<int> &tree, int sum) {
		vector<vector<TreeNode<int>*>> result;
		const TreeNode<T> *root = tree.getRootPtr();
		if (root == nullptr)
			return result;
		int level = 0;
		vector<TreeNode<int>*> buffer;
		searchAllPathsForSum(root, sum, buffer, level, result);
		return result;
	}

private:
	void addNodeToRoot(TreeNode<T> &curRoot, TreeNode<T> &node) {
		if (node.value >= curRoot.value) {
			if (curRoot.rightChild != nullptr)
				this->addNodeToRoot(*curRoot.rightChild, node);
			else
				curRoot.rightChild = &node;
		} else {
			if (curRoot.leftChild != nullptr)
				this->addNodeToRoot(*curRoot.leftChild, node);
			else
				curRoot.leftChild = &node;
		}
	}

	void addNodeToRootWithParent(TreeNode<T> &curRoot, TreeNode<T> &node,
			const TreeNode<T> &curParent) {
		if (node.value >= curRoot.value) {
			if (curRoot.rightChild != nullptr)
				this->addNodeToRootWithParent(*curRoot.rightChild, node,
						*curRoot.rightChild);
			else {
				curRoot.rightChild = &node;
				node.parent = &curRoot;
			}
		} else {
			if (curRoot.leftChild != nullptr)
				this->addNodeToRootWithParent(*curRoot.leftChild, node,
						*curRoot.leftChild);
			else {
				curRoot.leftChild = &node;
				node.parent = &curRoot;
			}
		}
	}

	void levelOrder(queue<TreeNode<T>*> &queue, vector<T> &vec) const {
		while (!queue.empty()) {
			auto top = queue.front();
			queue.pop();
			vec.push_back(top->value);
			if (top->leftChild)
				queue.push(top->leftChild);
			if (top->rightChild)
				queue.push(top->rightChild);
		}
	}

	void postOrder(const TreeNode<T>* node, vector<T> &vec) const {
		if (node) {
			postOrder(node->leftChild, vec);
			postOrder(node->rightChild, vec);
			vec.push_back(node->value);
		}
	}

	void preOrder(const TreeNode<T> *node, vector<T> &vec) const {
		if (node) {
			vec.push_back(node->value);
			preOrder(node->leftChild, vec);
			preOrder(node->rightChild, vec);
		}
	}

	void inOrder(const TreeNode<T> *node, vector<T> &vec) const {
		if (node) {
			inOrder(node->leftChild, vec);
			vec.push_back(node->value);
			inOrder(node->rightChild, vec);
		}
	}

	static int maxDepth(const TreeNode<T> *root) {
		if (root == nullptr)
			return 0;
		return 1 + max(maxDepth(root->leftChild), maxDepth(root->rightChild));
	}

	static int minDepth(const TreeNode<T> *root) {
		if (root == nullptr)
			return 0;
		return 1 + min(minDepth(root->leftChild), minDepth(root->rightChild));
	}

	TreeNode<T>* createFromArray(const vector<T> &values, int start, int end) {
		if (start > end || end < 0)
			return nullptr;
		int middleIndex = (start + end) / 2;
		_nodes.emplace_back(new TreeNode<T>(values[middleIndex]));
		auto last = _nodes.back().get();
		last->leftChild = createFromArray(values, start, middleIndex - 1);
		last->rightChild = createFromArray(values, middleIndex + 1, end);

		return last;
	}

	static const TreeNode<T> *leftMostChild(const TreeNode<T> &node) {
		const TreeNode<T> *child = &node;
		while (child->leftChild != nullptr)
			child = child->leftChild;
		return child;
	}

	static bool covers(const TreeNode<T> *root, const TreeNode<T> *target) {
		if (root == nullptr)
			return false;
		if (root == target)
			return true;
		return covers(root->leftChild, target)
				|| covers(root->rightChild, target);
	}

	static bool subTree(const TreeNode<T> *bigRoot,
			const TreeNode<T> *smallRoot) {
		if (bigRoot == nullptr) {
			return false;
		}
		if (bigRoot->value == smallRoot->value) {
			if (match(bigRoot, smallRoot))
				return true;
		}
		return subTree(bigRoot->leftChild, smallRoot)
				|| subTree(bigRoot->rightChild, smallRoot);
	}

	static bool match(const TreeNode<T> *bigRoot,
			const TreeNode<T> *smallRoot) {
		if (bigRoot == nullptr && smallRoot == nullptr)
			return true;
		if (bigRoot == nullptr || smallRoot == nullptr)
			return false;
		if (bigRoot->value != smallRoot->value)
			return false;
		return match(bigRoot->leftChild, smallRoot->leftChild)
				&& match(bigRoot->rightChild, smallRoot->rightChild);
	}

	static void searchAllPathsForSum(const TreeNode<int> *root, int sum,
			vector<TreeNode<int>*> &buffer, int level,
			vector<vector<TreeNode<int>*>> &result) {
		if (root == nullptr)
			return;
		int temp = sum;
		buffer.push_back(const_cast<TreeNode<int>*>(root));
		for (int i = level; i > -1; --i) {
			temp -= buffer[i]->value;
			if (temp == 0) {
				vector<TreeNode<int>*> path;
				for (int j = i; j <= level; j++) {
					path.push_back(buffer[j]);
				}
				result.push_back(path);
			}
		}
		vector<TreeNode<int>*> leftBuffer(buffer);
		vector<TreeNode<int>*> rightBuffer(buffer);
		searchAllPathsForSum(root->leftChild, sum, leftBuffer, level + 1,
				result);
		searchAllPathsForSum(root->rightChild, sum, rightBuffer, level + 1,
				result);
	}

	TreeNode<T>* _root;
	vector<unique_ptr<TreeNode<T>>> _nodes;
};

} /* namespace four */
#endif /* BINARYTREE_H_ */

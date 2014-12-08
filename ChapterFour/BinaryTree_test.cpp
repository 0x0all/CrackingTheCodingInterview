/*
 * BinaryTree_test.cpp
 *
 *  Created on: Nov 25, 2014
 *      Author: ubuntu
 */
#include <gtest/gtest.h>
#include <algorithm>
#include "BinaryTree.h"

using namespace std;

namespace chapterFour {

class BinaryTreeTest : public testing::Test {
public:
	BinaryTreeTest(): _fullIntBinaryTreeTwoLevels(0), _fullIntBinaryTreeTwoLevelsWithParentLinks(0){}
 protected:
  virtual void SetUp() {
	  _fullIntBinaryTreeTwoLevels = CreateFullIntTreeTwoLevels();
	  _fullIntBinaryTreeTwoLevelsWithParentLinks = CreateFullIntTreeTwoLevelsWithParentLinks();
	  _inOrderTraversalResult    = {5, 6, 7, 8, 9, 10, 11};
	  _preOrderTraversalResult   = {8, 6, 5, 7, 10, 9, 11};
	  _postOrderTraversalResult  = {5, 7, 6, 9, 11, 10, 8};
	  _levelOrderTraversalResult = {8, 6, 10, 5, 7, 9, 11};
	  _levelZeroNodeValues = {8};
	  _levelOneNodeValues = {6, 10};
	  _levelTwoNodeValues = {5, 7, 9, 11};
  }

  static BinaryTree<int> CreateFullIntTreeTwoLevels(){
  	BinaryTree<int> fullTree(8);
  	fullTree.addNode(6);
  	fullTree.addNode(10);
  	fullTree.addNode(5);
  	fullTree.addNode(7);
  	fullTree.addNode(9);
  	fullTree.addNode(11);
  	return fullTree;
  }

  static BinaryTree<int> CreateFullIntTreeTwoLevelsWithParentLinks(){
    	BinaryTree<int> fullTree(8);
    	fullTree.addNodeWithLinkToParent(6);
    	fullTree.addNodeWithLinkToParent(10);
    	fullTree.addNodeWithLinkToParent(5);
    	fullTree.addNodeWithLinkToParent(7);
    	fullTree.addNodeWithLinkToParent(9);
    	fullTree.addNodeWithLinkToParent(11);
    	return fullTree;
    }

  template<class T>
  static bool NodeNotNullWithExpectedValue(T expValue, shared_ptr<TreeNode<T>> node){
	  return node != nullptr && expValue == node->value;
  }

  template<class T>
  static bool VectorsAreEqual(const vector<T> &one, const vector<T> &other){
	  pair<vector<int>::const_iterator,vector<int>::const_iterator> mismachPair = mismatch(one.begin(), one.end(), other.begin());
	  return mismachPair.first == one.end() && mismachPair.second == other.end();
    }

  template<class T>
  static bool NodeValuesAreTheExpected(const vector<shared_ptr<TreeNode<T>>> &nodes, const vector<T> &expValues){
	 if(nodes.size() != expValues.size()) return false;
	 for(int i = 0; i < nodes.size(); i++){
		  if(!NodeNotNullWithExpectedValue(expValues.at(i), nodes.at(i)))
			  return false;
	  }
	 return true;
    }

  BinaryTree<int> _fullIntBinaryTreeTwoLevels;
  BinaryTree<int> _fullIntBinaryTreeTwoLevelsWithParentLinks;
  vector<int> _inOrderTraversalResult;
  vector<int> _preOrderTraversalResult;
  vector<int> _postOrderTraversalResult;
  vector<int> _levelOrderTraversalResult;
  vector<int> _levelZeroNodeValues;
  vector<int> _levelOneNodeValues;
  vector<int> _levelTwoNodeValues;

};

TEST_F(BinaryTreeTest, Constructor){
	BinaryTree<int> tree(1);
	shared_ptr<TreeNode<int> > root = tree.getRoot();

	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(1, root));
}

TEST_F(BinaryTreeTest, AddRightNode){
	BinaryTree<int> tree(1);
	tree.addNode(2);
	sptr_node<int> root = tree.getRoot();

	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(2, root->rightChild));
}

TEST_F(BinaryTreeTest, AddLeftNode){
	BinaryTree<int> tree(1);
	tree.addNode(2);
	tree.addNode(0);
	sptr_node<int> root = tree.getRoot();

	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(0, root->leftChild));
}

TEST_F(BinaryTreeTest, AddRightRightChild){
	BinaryTree<int> tree(1);
	tree.addNode(2);
	tree.addNode(0);
	tree.addNode(5);
	sptr_node<int> root = tree.getRoot();

	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(5, root->rightChild->rightChild));
}

TEST_F(BinaryTreeTest, AddLeftRightNode){
	BinaryTree<int> tree(8);
	tree.addNode(6);
	tree.addNode(10);
	tree.addNode(7);
	sptr_node<int> root = tree.getRoot();

	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(7, root->leftChild->rightChild));
}

TEST_F(BinaryTreeTest, InOrderTraversal){
	vector<int> result = _fullIntBinaryTreeTwoLevels.inOrderTraversalValues();

	ASSERT_TRUE(BinaryTreeTest::VectorsAreEqual<int>(result, _inOrderTraversalResult));
}

TEST_F(BinaryTreeTest, PreOrderTraversal){
	vector<int> result = _fullIntBinaryTreeTwoLevels.preOrderTraversalValues();

	ASSERT_TRUE(BinaryTreeTest::VectorsAreEqual<int>(result, _preOrderTraversalResult));
}

TEST_F(BinaryTreeTest, PostOrderTraversal){
	vector<int> result = _fullIntBinaryTreeTwoLevels.postOrderTraversalValues();

	ASSERT_TRUE(BinaryTreeTest::VectorsAreEqual<int>(result, _postOrderTraversalResult));
}

TEST_F(BinaryTreeTest, LevelOrderTraversal){
	vector<int> result = _fullIntBinaryTreeTwoLevels.levelOrderTraversalValues();

	ASSERT_TRUE(BinaryTreeTest::VectorsAreEqual<int>(result, _levelOrderTraversalResult));
}

TEST_F(BinaryTreeTest, IsBalanced){
	ASSERT_TRUE(_fullIntBinaryTreeTwoLevels.isBalanced());
}

TEST_F(BinaryTreeTest, IsBalancedOneDif){
	_fullIntBinaryTreeTwoLevels.addNode(12);

	ASSERT_TRUE(_fullIntBinaryTreeTwoLevels.isBalanced());
}

TEST_F(BinaryTreeTest, IsBalancedRightImbalance){
	_fullIntBinaryTreeTwoLevels.addNode(12);
	_fullIntBinaryTreeTwoLevels.addNode(13);

	ASSERT_FALSE(_fullIntBinaryTreeTwoLevels.isBalanced());
}

TEST_F(BinaryTreeTest, IsBalancedLeftImbalance){
	_fullIntBinaryTreeTwoLevels.addNode(4);
	_fullIntBinaryTreeTwoLevels.addNode(3);

	ASSERT_FALSE(_fullIntBinaryTreeTwoLevels.isBalanced());
}

TEST_F(BinaryTreeTest, IsBalancedRecursive){
	ASSERT_TRUE(_fullIntBinaryTreeTwoLevels.isBalancedRecursive());
}

TEST_F(BinaryTreeTest, IsBalancedOneDifRecursive){
	_fullIntBinaryTreeTwoLevels.addNode(12);

	ASSERT_TRUE(_fullIntBinaryTreeTwoLevels.isBalancedRecursive());
}

TEST_F(BinaryTreeTest, IsBalancedRightImbalanceRecursive){
	_fullIntBinaryTreeTwoLevels.addNode(12);
	_fullIntBinaryTreeTwoLevels.addNode(13);

	ASSERT_FALSE(_fullIntBinaryTreeTwoLevels.isBalancedRecursive());
}

TEST_F(BinaryTreeTest, IsBalancedLeftImbalanceRecursive){
	_fullIntBinaryTreeTwoLevels.addNode(4);
	_fullIntBinaryTreeTwoLevels.addNode(3);

	ASSERT_FALSE(_fullIntBinaryTreeTwoLevels.isBalancedRecursive());
}

TEST_F(BinaryTreeTest, CreationWithVectorEven){
	vector<int> vec = {0,1,2,3};
	BinaryTree<int> tree(vec);
	sptr_node<int> root = tree.getRoot();

	ASSERT_TRUE(tree.isBalanced());
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(1, root));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(0, root->leftChild));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(2, root->rightChild));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(3, root->rightChild->rightChild));
}

TEST_F(BinaryTreeTest, CreationWithVectorOdd){
	vector<int> vec = {0,1,2,3,4};
	BinaryTree<int> tree(vec);
	sptr_node<int> root = tree.getRoot();

	ASSERT_TRUE(tree.isBalanced());
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(2, root));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(0, root->leftChild));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(1, root->leftChild->rightChild));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(3, root->rightChild));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(4, root->rightChild->rightChild));
}

TEST_F(BinaryTreeTest, NodesPerLevel){
	map<int, vector_of_sptr_nodes<int>> result = _fullIntBinaryTreeTwoLevels.getNodesPerLevel();
	ASSERT_TRUE(BinaryTreeTest::NodeValuesAreTheExpected<int>(result[0], _levelZeroNodeValues));
	ASSERT_TRUE(BinaryTreeTest::NodeValuesAreTheExpected<int>(result[1], _levelOneNodeValues));
	ASSERT_TRUE(BinaryTreeTest::NodeValuesAreTheExpected<int>(result[2], _levelTwoNodeValues));
}

TEST_F(BinaryTreeTest, AddNodeNodesWithParent){
	sptr_node<int> root = _fullIntBinaryTreeTwoLevelsWithParentLinks.getRoot();

	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(8, root));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(10, root->rightChild));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(8, root->rightChild->parent));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(6, root->leftChild));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(8, root->leftChild->parent));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(11, root->rightChild->rightChild));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(10, root->rightChild->rightChild->parent));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(9, root->rightChild->leftChild));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(10, root->rightChild->leftChild->parent));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(7, root->leftChild->rightChild));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(6, root->leftChild->rightChild->parent));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(5, root->leftChild->leftChild));
	ASSERT_TRUE(BinaryTreeTest::NodeNotNullWithExpectedValue<int>(6, root->leftChild->leftChild->parent));
}

TEST_F(BinaryTreeTest, InOrderNext){
	sptr_node<int> root = _fullIntBinaryTreeTwoLevelsWithParentLinks.getRoot();
	map<int, vector_of_sptr_nodes<int>> result = _fullIntBinaryTreeTwoLevelsWithParentLinks.getNodesPerLevel();

	ASSERT_EQ(9, _fullIntBinaryTreeTwoLevelsWithParentLinks.inOrderNext(result[0].at(0))->value);
	ASSERT_EQ(7, _fullIntBinaryTreeTwoLevelsWithParentLinks.inOrderNext(result[1].at(0))->value);
	ASSERT_EQ(11, _fullIntBinaryTreeTwoLevelsWithParentLinks.inOrderNext(result[1].at(1))->value);
	ASSERT_EQ(6, _fullIntBinaryTreeTwoLevelsWithParentLinks.inOrderNext(result[2].at(0))->value);
	ASSERT_EQ(8, _fullIntBinaryTreeTwoLevelsWithParentLinks.inOrderNext(result[2].at(1))->value);
	ASSERT_EQ(10, _fullIntBinaryTreeTwoLevelsWithParentLinks.inOrderNext(result[2].at(2))->value);
}

TEST_F(BinaryTreeTest, CommonAncestor){
	sptr_node<int> root = _fullIntBinaryTreeTwoLevelsWithParentLinks.getRoot();
	map<int, vector_of_sptr_nodes<int>> result = _fullIntBinaryTreeTwoLevelsWithParentLinks.getNodesPerLevel();
	sptr_node<int> commonAncestor = BinaryTree<int>::commonAncestor(root, result[2].at(1), result[1].at(1));

	ASSERT_EQ(result[0].at(0), commonAncestor);
}

TEST_F(BinaryTreeTest, CommonAncestorTwo){
	sptr_node<int> root = _fullIntBinaryTreeTwoLevelsWithParentLinks.getRoot();
	map<int, vector_of_sptr_nodes<int>> result = _fullIntBinaryTreeTwoLevelsWithParentLinks.getNodesPerLevel();
	sptr_node<int> commonAncestor = BinaryTree<int>::commonAncestor(root, result[2].at(2), result[2].at(3));

	ASSERT_EQ(result[1].at(1), commonAncestor);
}

TEST_F(BinaryTreeTest, ContainsSubtreeIdenticalTrees){
	ASSERT_TRUE(BinaryTree<int>::containsSubTree(_fullIntBinaryTreeTwoLevelsWithParentLinks, _fullIntBinaryTreeTwoLevelsWithParentLinks));
}

TEST_F(BinaryTreeTest, ContainsSubtreeTrue){
	BinaryTree<int> smallTree(6);
	smallTree.addNodeWithLinkToParent(7);
	smallTree.addNodeWithLinkToParent(5);

	ASSERT_TRUE(BinaryTree<int>::containsSubTree(_fullIntBinaryTreeTwoLevelsWithParentLinks, smallTree));
}

TEST_F(BinaryTreeTest, ContainsSubtreeFalse){
	BinaryTree<int> smallTree(6);
	smallTree.addNodeWithLinkToParent(7);
	smallTree.addNodeWithLinkToParent(5);
	smallTree.addNodeWithLinkToParent(3);

	ASSERT_FALSE(BinaryTree<int>::containsSubTree(_fullIntBinaryTreeTwoLevelsWithParentLinks, smallTree));
}

TEST_F(BinaryTreeTest, FindAllPathsToSum){
	vector<vector_of_sptr_nodes<int>> result = BinaryTree<int>::findAllPathsToSum(_fullIntBinaryTreeTwoLevelsWithParentLinks, 19);

	ASSERT_FALSE(result.empty());
	ASSERT_EQ(2, result.size());
	ASSERT_EQ(3, result[0].size());
	ASSERT_EQ(8, result[0].at(0)->value);
	ASSERT_EQ(6, result[0].at(1)->value);
	ASSERT_EQ(5, result[0].at(2)->value);
	ASSERT_EQ(2, result[1].size());
	ASSERT_EQ(10, result[1].at(0)->value);
	ASSERT_EQ(9, result[1].at(1)->value);
}

} /* namespace four */

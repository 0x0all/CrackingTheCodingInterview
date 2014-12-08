/*
 * TreeNode_test.cpp
 *
 *  Created on: Nov 25, 2014
 *      Author: ubuntu
 */
#include <gtest/gtest.h>
#include "TreeNode.h"

using namespace std;

namespace chapterFour {

TEST(TreeNode, ToString){
	TreeNode<int> node(1);
	ASSERT_EQ("1", node.toString());
}

TEST(TreeNode, ToStringWithChildren){
	TreeNode<int> node(1);
	node.leftChild.reset(new TreeNode<int>(2));
	node.rightChild.reset(new TreeNode<int>(3));
	ASSERT_EQ("1 L: 2 R: 3", node.toStringWithChildren());
}

TEST(TreeNode, ToStringWithNullChildren){
	TreeNode<int> node(1);
	ASSERT_EQ("1 L: null R: null", node.toStringWithChildren());
}

TEST(TreeNode, IsLeafTrue){
	TreeNode<int> node(1);
	ASSERT_TRUE(node.isLeaf());
}

TEST(TreeNode, IsLeafFalseLeftChild){
	TreeNode<int> node(1);
	node.leftChild.reset(new TreeNode<int>(2));
	ASSERT_FALSE(node.isLeaf());
}

TEST(TreeNode, IsLeafFalseRightChild){
	TreeNode<int> node(1);
	node.rightChild.reset(new TreeNode<int>(2));
	ASSERT_FALSE(node.isLeaf());
}

} /* namespace four */

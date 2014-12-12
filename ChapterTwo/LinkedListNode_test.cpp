/*
 * LinkedListNode_test.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: ubuntu
 */

#include <iostream>
#include <string>
using namespace std;
#include <gtest/gtest.h>
#include "LinkedListNode.h"

namespace chapterTwo {

TEST(LinkedListNodeTest, NodeCreation) {
	LinkedListNode<int> node(5);
	ASSERT_EQ(5, node.data);
}

TEST(LinkedListNodeTest, TwoNodes) {
	LinkedListNode<int> head(5);
	head.appendToTail(3);
	ASSERT_EQ(3, head.next->data);
}

TEST(LinkedListNodeTest, RemoveHead) {
	LinkedListNode<int> head(5);
	head.appendToTail(2);
	head.appendToTail(3);
	LinkedListNode<int> newHead = LinkedListNode<int>::deleteNode(head, 5);
	ASSERT_EQ(2, newHead.data);
}

TEST(LinkedListNodeTest, RemoveMiddle) {
	LinkedListNode<int> head(5);
	head.appendToTail(2);
	head.appendToTail(3);
	LinkedListNode<int> newHead = LinkedListNode<int>::deleteNode(head, 2);
	ASSERT_EQ(3, newHead.next->data);
}

TEST(LinkedListNodeTest, RemoveTail) {
	LinkedListNode<int> head(5);
	head.appendToTail(2);
	head.appendToTail(3);
	LinkedListNode<int> newHead = LinkedListNode<int>::deleteNode(head, 3);
	ASSERT_TRUE(newHead.next->next == nullptr);
}

TEST(LinkedListNodeTest, RemoveDuplicatesNoDuplicate) {
	LinkedListNode<int> head(5);
	head.appendToTail(2);
	head.appendToTail(3);
	LinkedListNode<int> newHead = LinkedListNode<int>::removeDuplicates(head);
	ASSERT_EQ(5, newHead.data);
	ASSERT_EQ(2, newHead.next->data);
	ASSERT_EQ(3, newHead.next->next->data);
}

TEST(LinkedListNodeTest, RemoveDuplicatesDuplicatePrefix) {
	LinkedListNode<int> head(5);
	head.appendToTail(5);
	head.appendToTail(3);
	LinkedListNode<int> newHead = LinkedListNode<int>::removeDuplicates(head);
	ASSERT_EQ(5, newHead.data);
	ASSERT_EQ(3, newHead.next->data);
	ASSERT_TRUE(newHead.next->next == nullptr);
}

TEST(LinkedListNodeTest, RemoveDuplicatesDuplicateSuffix) {
	LinkedListNode<int> head(1);
	head.appendToTail(5);
	head.appendToTail(5);
	LinkedListNode<int> newHead = LinkedListNode<int>::removeDuplicates(head);
	ASSERT_EQ(1, newHead.data);
	ASSERT_EQ(5, newHead.next->data);
	ASSERT_TRUE(newHead.next->next == nullptr);
}

TEST(LinkedListNodeTest, RemoveDuplicatesNoHashNoDuplicate) {
	LinkedListNode<int> head(1);
	head.appendToTail(3);
	head.appendToTail(5);
	LinkedListNode<int> newHead = LinkedListNode<int>::removeDuplicatesNoHash(head);
	ASSERT_EQ(1, newHead.data);
	ASSERT_EQ(3, newHead.next->data);
	ASSERT_EQ(5, newHead.next->next->data);
}

TEST(LinkedListNodeTest, RemoveDuplicatesNoHashDuplicatePrefix) {
	LinkedListNode<int> head(5);
	head.appendToTail(5);
	head.appendToTail(3);
	LinkedListNode<int> newHead = LinkedListNode<int>::removeDuplicatesNoHash(head);
	ASSERT_EQ(5, newHead.data);
	ASSERT_EQ(3, newHead.next->data);
	ASSERT_TRUE(newHead.next->next == nullptr);
}

TEST(LinkedListNodeTest, RemoveDuplicatesNoHashDuplicateSufix) {
	LinkedListNode<int> head(1);
	head.appendToTail(5);
	head.appendToTail(5);
	LinkedListNode<int> newHead = LinkedListNode<int>::removeDuplicatesNoHash(head);
	ASSERT_EQ(1, newHead.data);
	ASSERT_EQ(5, newHead.next->data);
	ASSERT_TRUE(newHead.next->next == nullptr);
}

TEST(LinkedListNodeTest, Find1FromLast) {
	int idx = 1;
	LinkedListNode<int> head(1);
	head.appendToTail(5);
	head.appendToTail(9);
	ASSERT_EQ(5, LinkedListNode<int>::findFromLast(idx, head));
}

TEST(LinkedListNodeTest, Find2FromLast) {
	int idx = 2;
	LinkedListNode<int> head(1);
	head.appendToTail(5);
	head.appendToTail(9);
	ASSERT_EQ(1, LinkedListNode<int>::findFromLast(idx, head));
}

TEST(LinkedListNodeTest, Find3FromLast) {
	int idx = 3;
	LinkedListNode<int> head(1);
	head.appendToTail(5);
	head.appendToTail(9);
	ASSERT_THROW(LinkedListNode<int>::findFromLast(idx, head), RuntimeException);
}

TEST(LinkedListNodeTest, DeleteTheNodeHead) {
	LinkedListNode<int> head(1);
	head.appendToTail(5);
	head.appendToTail(9);
	LinkedListNode<int>::deleteTheNode(head);
	ASSERT_EQ(5, head.data);
	ASSERT_EQ(9, head.next->data);
	ASSERT_EQ(nullptr, head.next->next);
}

TEST(LinkedListNodeTest, DeleteTheNodeMiddle) {
	LinkedListNode<int> head(1);
	head.appendToTail(5);
	head.appendToTail(9);
	LinkedListNode<int>::deleteTheNode(*head.next);
	ASSERT_EQ(1, head.data);
	ASSERT_EQ(9, head.next->data);
	ASSERT_EQ(nullptr, head.next->next);
}

TEST(LinkedListNodeTest, DeleteTheNodeLast) {
	LinkedListNode<int> head(1);
	head.appendToTail(5);
	head.appendToTail(9);
	LinkedListNode<int>::deleteTheNode(*head.next->next);
	ASSERT_EQ(1, head.data);
	ASSERT_EQ(5, head.next->data);
	ASSERT_EQ(9, head.next->next->data);
	ASSERT_EQ(nullptr, head.next->next->next);
}


TEST(LinkedListNodeTest, AddSinleDigitNoCarry) {
	LinkedListNode<int> oneHead(1);
	LinkedListNode<int> twoHead(1);
	shared_ptr<LinkedListNode<int>> result = LinkedListNode<int>::add(oneHead, twoHead);
	ASSERT_EQ(2, result->data);
}

TEST(LinkedListNodeTest, AddSinleDigitCarry) {
	LinkedListNode<int> oneHead(9);
	LinkedListNode<int> twoHead(1);
	shared_ptr<LinkedListNode<int>> result = LinkedListNode<int>::add(oneHead, twoHead);
	ASSERT_EQ(0, result->data);
	ASSERT_EQ(1, result->next->data);
}

TEST(LinkedListNodeTest, AddTwoDigitCarry) {
	LinkedListNode<int> oneFirst(9);
	LinkedListNode<int> twoFirst(1);
	oneFirst.appendToTail(1);
	twoFirst.appendToTail(9);

	shared_ptr<LinkedListNode<int>> result = LinkedListNode<int>::add(oneFirst, twoFirst);
	ASSERT_EQ(0, result->data);
	ASSERT_EQ(1, result->next->data);
	ASSERT_EQ(1, result->next->next->data);
}

TEST(LinkedListNodeTest, FindLoopNodeLoopSize2) {
	shared_ptr<LinkedListNode<int>> head(new LinkedListNode<int>(1));
	head->appendToTail(2);
	head->appendToTail(3);
	head->next->next->next = head;
	const LinkedListNode<int> *loopNode = LinkedListNode<int>::findLoopNode(*head);
	ASSERT_EQ(1, loopNode->data);
}

TEST(LinkedListNodeTest, FindLoopNodeLoopSize1) {
	shared_ptr<LinkedListNode<int>> head(new LinkedListNode<int>(1));
	head->appendToTail(2);
	head->appendToTail(3);
	head->next->next->next = head->next;
	const LinkedListNode<int> *loopNode = LinkedListNode<int>::findLoopNode(*head);
	ASSERT_EQ(2, loopNode->data);
}

} /* namespace twotwo */

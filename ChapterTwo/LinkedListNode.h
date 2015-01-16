/*
 * LinkedListNode.h
 *
 *  Created on: Nov 19, 2014
 *      Author: ubuntu
 */

#ifndef LINKEDLISTNODE_H_
#define LINKEDLISTNODE_H_
#include <memory>
#include <unordered_map>
#include "RuntimeException.h"

namespace chapterTwo {

using namespace std;

template<class T>
class LinkedListNode {
public:
	LinkedListNode(T value) :
			data(value), next(nullptr) {
	}

	virtual ~LinkedListNode() {}

	void appendToTail(T value) {
		LinkedListNode<T>* n = this;
		while (n->next != nullptr) {
			n = n->next.get();
		}
		n->next = shared_ptr<LinkedListNode<T>>(new LinkedListNode(value));
	}

	LinkedListNode<T>& operator=(const LinkedListNode<T> &rhs) {
		if (this != &rhs) {
			this->data = rhs.data;
			this->next = rhs.next;
		}
		return *this;
	}

	bool operator==(const LinkedListNode<T> &other) {
		if (this == &other)
			return true;
		return other.data == this->data;
	}

	static LinkedListNode<T> deleteNode(LinkedListNode<T> &head, T value) {
		if (head.data == value) {
			head = *head.next;
			return head;
		}
		LinkedListNode<T>* n = &head;
		while (n->next != nullptr && n->next->data != value) {
			n = n->next.get();
		}
		if (n->next->data == value) {
			n->next = n->next->next;
		}
		return head;
	}
//	2.1:Write code to remove duplicates from an unsorted linked list.
	static LinkedListNode<T> removeDuplicates(LinkedListNode<T> &head) {
		unordered_map<T, bool> hash_map;
		LinkedListNode<T>* n = &head;
		hash_map[n->data] = true;
		while (n != nullptr && n->next != nullptr) {
			if (hash_map[n->next->data]) {
				shared_ptr<LinkedListNode<T>> tmp = n->next->next;
				n->next = tmp;
			} else
				hash_map[n->next->data] = true;
			n = n->next.get();
		}
		return head;
	}
//  2.1:Write code to remove duplicates from an unsorted linked list.
//	How would you solve this problem if a temporary buffer is not allowed?
	static LinkedListNode<T> removeDuplicatesNoHash(LinkedListNode<T> &head) {
		if (head.next == nullptr)
			return head;
		LinkedListNode<T>* cur = head.next.get();
		LinkedListNode<T>* run = &head;
		do {
			SearchForCurDuplicate(run, cur);
			cur = cur->next.get();
			run = &head;
		} while (cur != nullptr);

		return head;
	}
//  2.2:Implement an algorithm to find the nth to last element of a singly linked list.
	static T findFromLast(int n, const LinkedListNode<T> &head) {
		const LinkedListNode<T> *cur = &head;
		const LinkedListNode<T> *nToLast = &head;
		int forward = 0;

		while (cur->next != nullptr && forward < n) {
			cur = cur->next.get();
			++forward;
		}

		if (forward < n)
			throw RuntimeException();

		while (cur->next != nullptr) {
			cur = cur->next.get();
			nToLast = nToLast->next.get();
		}

		return nToLast->data;
	}
//	2.3:Implement an algorithm to delete a node in the middle of a single linked list, given
//	only access to that node.
	static void deleteTheNode(LinkedListNode<T> &node) {
			if (node.next != nullptr){
				node.data = node.next->data;
				node.next = node.next->next;
				if (node.next != nullptr)
					node.next->next = nullptr;
			}
		}



//	2.4: You have two numbers represented by a linked list, where each node contains a sin-
//	gle digit. The digits are stored in reverse order, such that the 1’s digit is at the head of
//	the list. Write a function that adds the two numbers and returns the sum as a linked
//	list.
	static shared_ptr<LinkedListNode<T>> add(const LinkedListNode<T> &one, const LinkedListNode<T> &other) {
		return addWithCarry(&one, &other, 0);
	}
//	2.5: Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
	static const LinkedListNode<T>* findLoopNode(const LinkedListNode<T> &head) {
		const LinkedListNode<T>* fast = &head;
		const LinkedListNode<T>* slow = &head;

		do {
			fast = fast->next->next.get();
			slow = slow->next.get();
		} while (fast != slow);

		slow = &head;

		 while (fast != slow) {
			fast = fast->next.get();
			slow = slow->next.get();
		}

		return fast;
	}

	T data;
	shared_ptr<LinkedListNode<T>> next;

private:
	static void SearchForCurDuplicate(LinkedListNode<T>* run, LinkedListNode<T>* cur) {
		while (run != cur) {
			if (cur->data == run->data) {
				removeDuplicateListItem(run, cur);
				break;
			}
			run = run->next.get();
		}
	}

	static void removeDuplicateListItem(LinkedListNode<T>* run, LinkedListNode<T>* cur) {
		while (run->next.get() != cur) {
			run = run->next.get();
		}
		run->next = cur->next;
	}

	static void deleteLinkeListRec(LinkedListNode<T> *head) {
		if (head->next != nullptr)
			deleteLinkeListRec(head->next);
		if (head->next != nullptr)
			delete head->next;
	}

	static shared_ptr<LinkedListNode<T>> addWithCarry(const LinkedListNode<T> *one, const LinkedListNode<T> *other, int carry) {
		int oneData = one == nullptr ? 0 : one->data;
		int otherData = other == nullptr ? 0 : other->data;
		int result = oneData + otherData + carry;
		int resultDigit = result % 10;
		int newCarry = result > 9 ? 1 : 0;

		shared_ptr<LinkedListNode<T>> resultNode(new LinkedListNode<T>(resultDigit));
		if (newCarry != 0 || (one != nullptr && one->next != nullptr)
				|| (other != nullptr && other->next != nullptr))
			resultNode->next = addWithCarry(one->next.get(), other->next.get(), newCarry);
		else
			resultNode->next = nullptr;

		return resultNode;
	}
};

} /* namespace twotwo */
#endif /* LINKEDLISTNODE_H_ */

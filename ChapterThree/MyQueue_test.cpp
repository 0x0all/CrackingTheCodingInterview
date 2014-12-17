/*
 * MyQueue_test.cpp
 *
 *  Created on: Dec 17, 2014
 *      Author: ubuntu
 */

#include <gtest/gtest.h>
#include "MyQueue.h"

namespace chapterThree {

TEST(MyQueueTest, PushOne){
	MyQueue<int> queue;
	queue.push(1);
	ASSERT_EQ(1, queue.pop());
}

TEST(MyQueueTest, PushMultiple){
	MyQueue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	ASSERT_EQ(1, queue.pop());
	ASSERT_EQ(2, queue.pop());
	ASSERT_EQ(3, queue.pop());
	ASSERT_EQ(4, queue.pop());
}

TEST(MyQueueTest, PushPopMixed){
	MyQueue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.pop();
	queue.push(3);
	queue.push(4);
	queue.pop();
	ASSERT_EQ(3, queue.pop());
	ASSERT_EQ(4, queue.pop());
}

} /* namespace four */

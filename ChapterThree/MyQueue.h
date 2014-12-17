/*
 * MyQueue.h
 *
 *  Created on: Dec 17, 2014
 *      Author: ubuntu
 */

#ifndef MYQUEUE_H_
#define MYQUEUE_H_
#include <stack>
#include <algorithm>

using namespace std;

namespace chapterThree {
template<class T>
class MyQueue{
public:
	MyQueue(){}
	virtual ~MyQueue(){}
	void push(T value){first.push(value);}
	T pop(){
		moveAll(first, second);
		auto top = second.top();
		second.pop();
		moveAll(second, first);
		return top;
	}
private:
	void moveAll(stack<T> &sourceStack, stack<T> &targetStack){
		while(!sourceStack.empty())
			moveTop(sourceStack, targetStack);
	}
	void moveTop(stack<T> &sourceStack, stack<T> &targetStack){
		if(!sourceStack.empty()){
			targetStack.push(sourceStack.top());
			sourceStack.pop();
		}
	}
	stack<T> first;
	stack<T> second;
};

} /* namespace four */
#endif /* MYQUEUE_H_ */

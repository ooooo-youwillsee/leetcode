//
// Created by ooooo on 2019/12/30.
//
#ifndef CPP_0155_SOLUTION1_H
#define CPP_0155_SOLUTION1_H

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// minStack and stack are in one-to-one correspondence
class MinStack {

 private:

	stack<int> stack, minStack;

 public:

	MinStack() {
		minStack.push(INT_MIN);
	}

	void push(int val) {
		stack.push(val);
		minStack.push(min(minStack.top(), val));
	}

	void pop() {
		stack.pop();
	}

	int top() {
		return stack.top();
	}

	int getMin() {
		return minStack.top();
	}
};

#endif //CPP_0155_SOLUTION1_H

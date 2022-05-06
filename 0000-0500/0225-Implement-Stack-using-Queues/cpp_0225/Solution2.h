//
// Created by ooooo on 2019/10/30.
//
#ifndef CPP_0225_SOLUTION2_H
#define CPP_0225_SOLUTION2_H

#include <iostream>
#include <queue>

using namespace std;


class MyStack {

private:
    deque<int> q;

public:

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q.back();
        q.pop_back();
        return res;
    }

    /** Get the top element. */
    int top() {
        return q.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

#endif //CPP_0225_SOLUTION2_H

//
// Created by ooooo on 2019/10/30.
//
#ifndef CPP_0225_SOLUTION1_H
#define CPP_0225_SOLUTION1_H

#include <iostream>
#include <queue>

using namespace std;


class MyStack {

private:
    queue<int> q;

public:

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {

        for (int i = 0, len = q.size() - 1; i < len; ++i) {
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        return res;
    }

    /** Get the top element. */
    int top() {
        for (int i = 0, len = q.size() - 1; i < len; ++i) {
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.push(res);
        q.pop();
        return res;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

#endif //CPP_0225_SOLUTION1_H

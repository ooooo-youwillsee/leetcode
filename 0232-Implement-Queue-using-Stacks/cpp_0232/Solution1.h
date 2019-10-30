//
// Created by ooooo on 2019/10/30.
//
#ifndef CPP_0232_SOLUTION1_H
#define CPP_0232_SOLUTION1_H

#include <stack>
#include <iostream>

using namespace std;

class MyQueue {

private:
    stack<int> in;
    stack<int> out;
    int front;

public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if(in.empty()) {
            front = x;
        }
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
        int res = out.top();
        out.pop();
        if (!out.empty()) {
            front = out.top();
        }

        while (!out.empty()) {
            in.push(out.top());
            out.pop();
        }

        return res;
    }

    /** Get the front element. */
    int peek() {
        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

#endif //CPP_0232_SOLUTION1_H

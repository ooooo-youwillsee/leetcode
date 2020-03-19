//
// Created by ooooo on 2020/3/19.
//
#ifndef CPP_030__SOLUTION2_H_
#define CPP_030__SOLUTION2_H_

#include <iostream>
#include <stack>

using namespace std;

/**
 * 使用一个辅助栈：最小栈
 */
class MinStack {

 private:
  stack<int> s, min_s;

 public:
  /** initialize your data structure here. */
  MinStack() {
  }

  void push(int x) {
    if (min_s.empty()) {
      min_s.push(x);
    } else {
      if (x < min_s.top()) {
        min_s.push(x);
      } else {
        min_s.push(min_s.top());
      }
    }
    s.push(x);
  }

  void pop() {
    s.pop();
    min_s.pop();
  }

  int top() {
    return s.top();
  }

  int min() {
    return min_s.top();
  }
};

#endif //CPP_030__SOLUTION2_H_

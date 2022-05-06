//
// Created by ooooo on 2020/3/8.
//
#ifndef CPP_009__SOLUTION1_H_
#define CPP_009__SOLUTION1_H_

#include <iostream>
#include <stack>

using namespace std;

class CQueue {

 private:
  stack<int> s1, s2;
 public:
  CQueue() {
  }

  void appendTail(int value) {
    s1.push(value);
  }

  int deleteHead() {
    if (s1.empty() && s2.empty()) return -1;
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int ret = s2.top();
    s2.pop();
    return ret;
  }
};

#endif //CPP_009__SOLUTION1_H_

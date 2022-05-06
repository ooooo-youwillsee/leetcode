//
// Created by ooooo on 2020/4/25.
//
#ifndef CPP_059_2__SOLUTION1_H_
#define CPP_059_2__SOLUTION1_H_

#include <iostream>
#include <deque>
#include <unordered_map>

using namespace std;

class MaxQueue {
 public:

  deque<int> q, help;
  MaxQueue() {
    q.clear();
    help.clear();
  }

  int max_value() {
    if (q.empty()) return -1;
    return help.front();
  }

  void push_back(int value) {
    q.push_back(value);
    while (!help.empty() && help.back() < value) help.pop_back();
    help.push_back(value);
  }

  int pop_front() {
    if (q.empty()) return -1;
    int ret = q.front();
    q.pop_front();
    if (help.front() == ret) help.pop_front();
    return ret;
  }
};

#endif //CPP_059_2__SOLUTION1_H_

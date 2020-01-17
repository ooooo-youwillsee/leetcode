//
// Created by ooooo on 2020/1/17.
//
#ifndef CPP_0961__SOLUTION1_H_
#define CPP_0961__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int repeatedNTimes(vector<int> &A) {
    unordered_set<int> s;
    for (auto item: A) {
      if (s.count(item)) return item;
      s.insert(item);
    }
    return -1;
  }
};

#endif //CPP_0961__SOLUTION1_H_

//
// Created by ooooo on 2020/3/25.
//
#ifndef CPP_040__SOLUTION1_H_
#define CPP_040__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 堆
 */
class Solution {
 public:
  vector<int> getLeastNumbers(vector<int> &arr, int k) {
    if (k == 0) return {};
    priority_queue<int> q;
    for (auto &num: arr) {
      if (q.size() < k) {
        q.push(num);
      } else {
        if (q.top() > num) {
          q.pop();
          q.push(num);
        }
      }
    }
    vector<int> ans;
    for (int i = 0; i < k; ++i) {
      ans.push_back(q.top());
      q.pop();
    }
    return ans;
  }
};

#endif //CPP_040__SOLUTION1_H_

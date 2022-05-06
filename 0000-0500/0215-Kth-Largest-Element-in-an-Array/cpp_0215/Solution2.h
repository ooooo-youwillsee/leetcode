//
// Created by ooooo on 2020/2/20.
//
#ifndef CPP_0215__SOLUTION2_H_
#define CPP_0215__SOLUTION2_H_

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/**
 * heap
 */
class Solution {
 public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto &num: nums) {
      if (q.size() < k) {
        q.push(num);
      } else {
        if (q.top() < num) {
          q.pop();
          q.push(num);
        }
      }
    }
    return q.top();
  }
};

#endif //CPP_0215__SOLUTION2_H_

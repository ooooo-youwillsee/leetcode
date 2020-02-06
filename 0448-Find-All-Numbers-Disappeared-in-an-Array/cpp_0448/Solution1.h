//
// Created by ooooo on 2020/2/6.
//
#ifndef CPP_0448__SOLUTION1_H_
#define CPP_0448__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    vector<int> ans;
    for (int i = 1; i <= nums.size(); ++i) {
      if (!set.count(i)) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

#endif //CPP_0448__SOLUTION1_H_

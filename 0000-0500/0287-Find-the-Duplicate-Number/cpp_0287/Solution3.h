//
// Created by ooooo on 2020/2/23.
//
#ifndef CPP_0287__SOLUTION3_H_
#define CPP_0287__SOLUTION3_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * binary search
 * 对区间[l, r]中查找 l <= X <= mid 的个数count,
 *  如果 count > mid - l + 1; 就说明重复的数字在 [l, mid]
 *  反之，重复的数字在 [mid+1, r]
 */
class Solution {
 public:
  int findDuplicate(vector<int> &nums) {
    int l = 1, r = nums.size() - 1, mid = 0, count = 0;
    while (l < r) {
      mid = l + (r - l) / 2;
      count = 0;
      // find  l <= X <=mid 的个数
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] <= mid && nums[i] >= l) count++;
      }
      if (count > mid - l + 1) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
#endif //CPP_0287__SOLUTION3_H_

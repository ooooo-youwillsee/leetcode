//
// Created by ooooo on 2020/4/8.
//
#ifndef CPP_051__SOLUTION1_H_
#define CPP_051__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  int __merge(int l, int mid, int r, vector<int> &tmp) {
    int i = mid, j = r, count = 0, k = r;
    for (int p = l; p <= r; ++p) {
      tmp[p] = nums[p];
    }
    while (i >= l && j >= mid + 1) {
      if (tmp[i] > tmp[j]) {
        nums[k--] = tmp[i--];
        count += j - mid;
      } else {
        nums[k--] = tmp[j--];
      }
    }
    for (; i >= l; i--) {
      nums[k--] = tmp[i];
    }
    for (; j >= mid + 1; j--) {
      nums[k--] = tmp[j];
    }
    return count;
  }

  int merge(int l, int r, vector<int> &tmp) {
    if (l >= r) {
      return 0;
    }
    int mid = l + (r - l) / 2;
    int left = merge(l, mid, tmp);
    int right = merge(mid + 1, r, tmp);
    return left + right + __merge(l, mid, r, tmp);
  }

  vector<int> nums;

  int reversePairs(vector<int> &nums) {
    this->nums = nums;
    vector<int> tmp(nums.size(), 0);
    return merge(0, nums.size() - 1, tmp);
  }
};

#endif //CPP_051__SOLUTION1_H_

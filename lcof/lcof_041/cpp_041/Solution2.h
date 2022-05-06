//
// Created by ooooo on 2020/3/26.
//
#ifndef CPP_041__SOLUTION2_H_
#define CPP_041__SOLUTION2_H_

#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
 private:

  vector<int> nums;

 public:
  /** initialize your data structure here. */
  MedianFinder() {
  }

  void addNum(int num) {
    if (nums.empty()) nums.emplace_back(num);
    else nums.insert(lower_bound(nums.begin(), nums.end(), num), num);
  }

  double findMedian() {
    int mid = nums.size() / 2;
    return (nums.size() & 1) == 0 ? (nums[mid - 1] + nums[mid]) / 2.0 : nums[mid];
  }
};

#endif //CPP_041__SOLUTION2_H_

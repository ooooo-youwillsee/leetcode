//
// Created by ooooo on 2020/1/20.
//
#ifndef CPP_0744__SOLUTION1_H_
#define CPP_0744__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 *  binary search
 */
class Solution {
 public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    if (target < letters[0] || target >= letters[letters.size() - 1]) return letters[0];
    int left = 0, right = letters.size() - 1, mid = 0;
    while (left < right) {
      mid = left + (right - left) / 2;
      // 思考不存在的情况再缩小搜索空间
      if (letters[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return letters[left];
  }
};

#endif //CPP_0744__SOLUTION1_H_

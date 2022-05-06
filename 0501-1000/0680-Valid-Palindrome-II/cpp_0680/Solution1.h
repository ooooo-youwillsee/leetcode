//
// Created by ooooo on 2020/1/28.
//
#ifndef CPP_0680__SOLUTION1_H_
#define CPP_0680__SOLUTION1_H_

#include <iostream>

using namespace std;


/**
 * 超出内存限制
 */
class Solution {
 public:

  bool isValid(string s, int pos) {
    for (int left = 0, right = s.size() - 1; left < right; ++left, --right) {
      if (left == pos) left++;
      else if (right == pos) right--;
      if (s[left] != s[right]) return false;
    }
    return true;
  }

  bool validPalindrome(string s) {
    // s.size 是unsigned 无法和-1正常比较
    for (int i = s.size(); i >= 0; --i) {
      if (isValid(s, i)) return true;
    }
    return false;
  }
};

#endif //CPP_0680__SOLUTION1_H_

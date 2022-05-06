//
// Created by ooooo on 2020/1/28.
//
#ifndef CPP_0680__SOLUTION2_H_
#define CPP_0680__SOLUTION2_H_

#include <iostream>

using namespace std;

/**
 * 递归
 */
class Solution {
 public:

  bool validPalindrome(string s, int left, int right, bool deleted) {
    if (left >= right) return true;
    if (s[left] == s[right]) {
      return validPalindrome(s, left + 1, right - 1, deleted);
    }
    if (deleted) return false;
    return validPalindrome(s, left + 1, right, true) || validPalindrome(s, left, right - 1, true);
  }

  bool validPalindrome(string s) {
    return validPalindrome(s, 0, s.size() - 1, false);
  }
};

#endif //CPP_0680__SOLUTION2_H_

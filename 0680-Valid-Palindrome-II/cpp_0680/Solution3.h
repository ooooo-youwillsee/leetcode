//
// Created by ooooo on 2020/1/28.
//
#ifndef CPP_0680__SOLUTION3_H_
#define CPP_0680__SOLUTION3_H_

#include <iostream>

using namespace std;

/**
 * 双指针, 有一个不相等的字符， 就比较 【left-1, right】和 【left, right-1】
 */
class Solution {
 public:

  bool validPalindrome(string s) {
    for (int left = 0, right = s.size() - 1; left <= right; ++left, --right) {
      if (s[left] != s[right]) {
        return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
      }
    }
    return true;
  }

  bool isPalindrome(string s, int left, int right) {
    while (left < right) {
      if (s[left++] != s[right--]) {
        return false;
      }
    }
    return true;
  }
};

#endif //CPP_0680__SOLUTION3_H_

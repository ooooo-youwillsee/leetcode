//
// Created by ooooo on 2020/1/30.
//
#ifndef CPP_0696__SOLUTION1_H_
#define CPP_0696__SOLUTION1_H_

#include <iostream>

using namespace std;

/**
 * 暴力法
 */
class Solution {
 public:

  bool valid(string &s, int left, int right) {
    char leftC = s[left++], rightC = s[right--];
    if (leftC == rightC) return false;
    while (left < right) {
      if (s[left] != leftC || s[right] != rightC || s[left++] == s[right--]) return false;
    }
    return true;
  }

  int countBinarySubstrings(string s) {
    int ans = 0;
    for (int i = 2; i <= s.size(); i += 2) {
      // 每一个j都扫描一遍
      for (int j = 0; j <= s.size() - i; j++) {
        if (valid(s, j, j + i - 1)) {
          ans += 1;
        }
      }
    }
    return ans;
  }
};

#endif //CPP_0696__SOLUTION1_H_

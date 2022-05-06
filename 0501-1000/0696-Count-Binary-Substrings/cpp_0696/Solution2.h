//
// Created by ooooo on 2020/1/30.
//
#ifndef CPP_0696__SOLUTION2_H_
#define CPP_0696__SOLUTION2_H_

#include <iostream>

using namespace std;

/**
 * 上一个连续字符的个数和当前连续字符的个数
 */
class Solution {
 public:

  int countBinarySubstrings(string s) {
    int ans = 0, prev = 0, cur = 1;
    for (int i = 0; i < s.size(); ++i) {
      if (i != s.size() - 1 && s[i] == s[i + 1]) {
        cur++;
      } else {
        ans += min(prev, cur);
        prev = cur;
        cur = 1;
      }
    }
    return ans;
  }
};

#endif //CPP_0696__SOLUTION2_H_

//
// Created by ooooo on 2020/1/18.
//
#ifndef CPP_0392__SOLUTION1_H_
#define CPP_0392__SOLUTION1_H_

#include <iostream>

using namespace std;

/**
 * 暴力破解 double loop
 */
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int ans = 0, i = 0;
    for (auto &c: s) {
      while (i < t.size()) {
        if (t[i++] == c) {
          ans++;
          break;
        }
      }
    }
    return ans == s.size();
  }
};

#endif //CPP_0392__SOLUTION1_H_

//
// Created by ooooo on 2020/1/18.
//
#ifndef CPP_0392__SOLUTION2_H_
#define CPP_0392__SOLUTION2_H_

#include <iostream>

using namespace std;

/**
 * find_first_of
 */
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int i = 0;
    for (auto c:s) {
      int j = t.find_first_of(c, i);
      if (j == -1) return false;
      i = j + 1;
    }
    return true;
  }
};

#endif //CPP_0392__SOLUTION2_H_

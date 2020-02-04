//
// Created by ooooo on 2020/2/4.
//
#ifndef CPP_1332__SOLUTION1_H_
#define CPP_1332__SOLUTION1_H_

#include <iostream>

using namespace std;

/**
 * 做多为两次。 因为n个a本身就是子序列，所以先删除所有的a,再删除所有的b
 */
class Solution {
 public:

  int removePalindromeSub(string s) {
    for (int left = 0, right = s.size() - 1; left < right; ++left, --right) {
      if (s[left] != s[right]) return 2;
    }
    return s.size() == 0 ? 0 : 1;
  }
};

#endif //CPP_1332__SOLUTION1_H_

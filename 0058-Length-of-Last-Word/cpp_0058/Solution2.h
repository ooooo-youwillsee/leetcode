//
// Created by ooooo on 2020/1/25.
//
#ifndef CPP_0058__SOLUTION2_H_
#define CPP_0058__SOLUTION2_H_

#include <iostream>

using namespace std;

/**
 * 从尾遍历头
 */
class Solution {
 public:
  int lengthOfLastWord(string s) {
    int end = s.size() - 1;
    while (end >= 0 && s[end] == ' ') end--;
    if (end < 0) return 0;
    int start = end - 1;
    while (start >= 0 && s[start] != ' ') start--;
    return end - start;
  }
};

#endif //CPP_0058__SOLUTION2_H_

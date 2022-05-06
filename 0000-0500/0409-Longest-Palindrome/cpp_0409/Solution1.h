//
// Created by ooooo on 2020/1/11.
//
#ifndef CPP_0409__SOLUTION1_H_
#define CPP_0409__SOLUTION1_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int longestPalindrome(string s) {
    if (s.empty()) return 0;
    unordered_map<char, int> m;
    for (auto &c: s) {
      m[c]++;
    }
    int i = 0, j = 0;
    for (auto &entry: m) {
      j += entry.second / 2;
      if (entry.second % 2 == 1) {
        // 有多余的置为1
        i = 1;
      }
    }

    return i + j * 2;
  }
};

#endif //CPP_0409__SOLUTION1_H_

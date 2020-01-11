//
// Created by ooooo on 2020/1/11.
//
#ifndef CPP_0387__SOLUTION1_H_
#define CPP_0387__SOLUTION1_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    unordered_map<char, int> m;
    for (auto &c: s) {
      m[c]++;
    }
    for (int i = 0; i < s.size(); ++i) {
      //  s[i]的数量为1，表示只有一个，也就是不重复的字符
      if (m[s[i]] == 1) return i;
    }
    return -1;
  }
};

#endif //CPP_0387__SOLUTION1_H_

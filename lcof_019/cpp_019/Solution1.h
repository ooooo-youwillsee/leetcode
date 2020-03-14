//
// Created by ooooo on 2020/3/14.
//
#ifndef CPP_019__SOLUTION1_H_
#define CPP_019__SOLUTION1_H_

#include <iostream>
#include <vector>


#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  bool dfs(int i, int j) {
    if (i >= s.size() && j >= p.size()) return true;
    if (i < s.size() && j == p.size()) return false;
    // 后面的字符要么存在 '*'，要么不存在
    if (j + 1 < p.size() && p[j + 1] == '*') {
      if (p[j] == s[i] || (p[j] == '.' && i < s.size())) {
        return dfs(i, j + 2) || dfs(i + 1, j) || dfs(i + 1, j + 2);
      } else {
        // 直接忽略 '*'
        return dfs(i, j + 2);
      }
    }
    if (p[j] == s[i] || (p[j] == '.' && i < s.size())) {
      return dfs(i + 1, j + 1);
    }
    return false;
  }

  string s, p;

  bool isMatch(string s, string p) {
    if (s.empty() && p.empty()) return true;
    this->s = s;
    this->p = p;
    return dfs(0, 0);
  }
};

#endif //CPP_019__SOLUTION1_H_

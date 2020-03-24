//
// Created by ooooo on 2020/3/24.
//
#ifndef CPP_038__SOLUTION2_H_
#define CPP_038__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:

  void dfs(int i) {
    if (i == s.size()) ans.push_back(s);
    for (int j = i, len = s.size(); j < len; ++j) {
      if (skip(i, j)) continue;
      swap(s[j], s[i]);
      dfs(i + 1);
      swap(s[j], s[i]);
    }
  }

  vector<string> ans;

  string s;
  vector<string> permutation(string s) {
    this->s = s;
    dfs(0);
    return ans;
  }

  /**
   * [i,j-1]区间中有s[j]的重复项则跳过
   */
  bool skip(int i, int j) {
    for (; i < j; ++i) {
      if (s[i] == s[j]) return true;
    }
    return false;
  }
};

#endif //CPP_038__SOLUTION2_H_

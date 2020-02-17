//
// Created by ooooo on 2020/2/17.
//
#ifndef CPP_0139__SOLUTION2_H_
#define CPP_0139__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 记忆化 记录索引 i 的位置
 */
class Solution {
 public:

  unordered_set<string> word_set;
  vector<int> memo;

  bool help(string s, int i) {
    if (i == s.length()) return true;
    if (memo[i] != 0) return memo[i] == 1;
    for (int j = i + 1; j <= s.length(); j++) {
      if (word_set.count(s.substr(i, j - i)) && help(s, j)) {
        memo[i] = 1;
        return true;
      }
    }
    memo[i] = 2;
    return false;
  }

  bool wordBreak(string s, vector<string> &wordDict) {
    word_set.insert(wordDict.begin(), wordDict.end());
    // 0 表示没有访问过, 1 表示 true, 2 表示 false
    memo.assign(s.length(), 0);
    return help(s, 0);
  }
};

#endif //CPP_0139__SOLUTION2_H_

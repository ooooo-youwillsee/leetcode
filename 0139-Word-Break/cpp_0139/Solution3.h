//
// Created by ooooo on 2020/2/17.
//
#ifndef CPP_0139__SOLUTION3_H_
#define CPP_0139__SOLUTION3_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 记忆化 记录索引 i 的位置
 */
class Solution {
 public:

  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> word_set(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.length() + 1, false);
    // 0 表示空字符串
    dp[0] = true;
    for (int i = 1; i <= s.length(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (dp[j] && word_set.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[s.length()];
  }
};

#endif //CPP_0139__SOLUTION3_H_

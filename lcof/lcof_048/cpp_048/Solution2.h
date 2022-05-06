//
// Created by ooooo on 2020/4/5.
//
#ifndef CPP_048__SOLUTION2_H_
#define CPP_048__SOLUTION2_H_

#include <iostream>
#include <vector>
using namespace std;

/**
 * dp[i] = dp[i-1] + 1
 *
 * dp[i] 表示以第 i 个字符为尾的长度
 */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size(), ans = 0;
    // map 中的 -1 表示没有出现过, >0 表示出现的索引位置
    vector<int> dp(n + 1, 0), map(256, -1);
    for (int i = 0; i < n; ++i) {
      int preIndex = map[s[i]];
      if (preIndex == -1) {
        dp[i + 1] = dp[i] + 1;
      } else {
        int diff = i - preIndex;
        if (diff <= dp[i]) {
          dp[i + 1] = diff;
        } else {
          dp[i + 1] = dp[i] + 1;
        }
      }
      map[s[i]] = i;
      ans = max(ans, dp[i + 1]);
    }
    return ans;
  }
};

#endif //CPP_048__SOLUTION2_H_

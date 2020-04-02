//
// Created by ooooo on 2020/4/2.
//
#ifndef CPP_046__SOLUTION2_H_
#define CPP_046__SOLUTION2_H_

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * dp[i] = dp[i+1] + ( valid ？ dp[i+2] : 0  )
 */
class Solution {
 public:

  int valid(int i) {
    if (i + 1 >= s.size() || s[i] == '0' || s[i] > '2') return false;
    if (s[i] == '1') return true;
    return s[i] == '2' && s[i + 1] < '6';
  }

  string s;

  int translateNum(int num) {
    this->s = to_string(num);
    int len = s.size();
    vector<int> dp(len + 1);
    dp[len] = 1;
    for (int i = len - 1; i >= 0; --i) {
      dp[i] = dp[i + 1] + (valid(i) ? dp[i + 2] : 0);
    }
    return dp[0];
  }
};

#endif //CPP_046__SOLUTION2_H_

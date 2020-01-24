//
// Created by ooooo on 2020/1/24.
//
#ifndef CPP_0014__SOLUTION1_H_
#define CPP_0014__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  string check(string s1, string s2) {
    int len = s1.size() < s2.size() ? s1.size() : s2.size();
    string ans = "";
    for (int i = 0; i < len; ++i) {
      if (s1[i] != s2[i]) return ans;
      ans += string(1, s1[i]);
    }
    return ans;
  }
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return "";
    string ans = strs[0];
    for (int i = 1; i < strs.size(); ++i) {
      ans = check(ans, strs[i]);
    }
    return ans;
  }
};

#endif //CPP_0014__SOLUTION1_H_

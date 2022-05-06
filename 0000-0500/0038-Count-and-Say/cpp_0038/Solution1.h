//
// Created by ooooo on 2020/1/24.
//
#ifndef CPP_0038__SOLUTION1_H_
#define CPP_0038__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:

  string help(string s) {
    int count = 1;
    string ans = "";
    for (int i = 0; i < s.size(); ++i) {
      if (i == s.size() - 1 || s[i] != s[i + 1]) {
        ans += to_string(count) + string(1, s[i]);
        count = 1;
      } else {
        count++;
      }
    }
    return ans;
  }
  string countAndSay(int n) {
    string ans = "1";
    for (int i = 1; i < n; ++i) {
      ans = help(ans);
    }
    return ans;
  }
};

#endif //CPP_0038__SOLUTION1_H_

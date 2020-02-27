//
// Created by ooooo on 2020/2/27.
//
#ifndef CPP_0394__SOLUTION2_H_
#define CPP_0394__SOLUTION2_H_

#include <iostream>

using namespace std;

/**
 * dfs
 */
class Solution {
 public:

  string multipleStr(string s, int count) {
    string ans = "";
    for (int i = 0; i < count; ++i) {
      ans += s;
    }
    return ans;
  }

  pair<string, int> dfs(string &s, int i) {
    int multi = 0;
    string ans = "";
    while (i < s.size()) {
      if (isdigit(s[i])) {
        multi = multi * 10 + s[i] - '0';
      } else if (s[i] == '[') {
        auto res = dfs(s, i + 1);
        ans += multipleStr(res.first, multi);
        i = res.second;
        multi = 0;
      } else if (s[i] == ']') {
        return {ans, i};
      } else {
        ans.push_back(s[i]);
      }
      i++;
    }
    return {ans, i};
  }

  string decodeString(string s) {
    return dfs(s, 0).first;
  }
};

#endif //CPP_0394__SOLUTION2_H_

//
// Created by ooooo on 2020/3/24.
//
#ifndef CPP_038__SOLUTION1_H_
#define CPP_038__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:

  void dfs(string &str) {
    if (str.size() == s.size()) {
      str_set.insert(str);
      return;
    }
    for (int i = 0, len = s.size(); i < len; ++i) {
      if (s[i] == '$') continue;
      str.push_back(s[i]);
      s[i] = '$';
      dfs(str);
      s[i] = str[str.size() - 1];
      str.pop_back();
    }
  }

  unordered_set<string> str_set;

  string s;
  vector<string> permutation(string s) {
    this->s = s;
    string str = "";
    dfs(str);
    vector<string> ans;
    for (auto &item: str_set) ans.emplace_back(item);
    return ans;
  }
};

#endif //CPP_038__SOLUTION1_H_

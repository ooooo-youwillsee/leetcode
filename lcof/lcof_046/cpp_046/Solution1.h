//
// Created by ooooo on 2020/4/2.
//
#ifndef CPP_046__SOLUTION1_H_
#define CPP_046__SOLUTION1_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:

  int valid(int i) {
    if (i + 1 >= s.size() || s[i] == '0' || s[i] > '2') return false;
    if (s[i] == '1') return true;
    return s[i] == '2' && s[i + 1] < '6';
  }

  int dfs(int i) {
    if (m.count(i)) return m[i];
    if (i == s.size()) return 1;
    if (i > s.size()) return 0;
    int ans = dfs(i + 1);
    if (valid(i)) {
      ans += dfs(i + 2);
    }
    return m[i] = ans;
  }

  string s;
  unordered_map<int, int> m;

  int translateNum(int num) {
    this->s = to_string(num);
    return dfs(0);
  }
};

#endif //CPP_046__SOLUTION1_H_

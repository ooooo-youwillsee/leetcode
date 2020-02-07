//
// Created by ooooo on 2020/2/7.
//
#ifndef CPP_0017__SOLUTION1_H_
#define CPP_0017__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  vector<vector<string>> letters = {
      {"a", "b", "c"},
      {"d", "e", "f"},
      {"g", "h", "i"},
      {"j", "k", "l"},
      {"m", "n", "o"},
      {"p", "q", "r", "s"},
      {"t", "u", "v"},
      {"w", "x", "y", "z"},
  };

  vector<string> ans;

  void help(string s, string &digits, int i) {
    if (i == digits.size()) {
      ans.push_back(s);
      return;
    }
    for (auto letter: letters[digits[i] - '2']) {
      help(s + letter, digits, i + 1);
    }
  }

  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    ans.clear();
    help("", digits, 0);
    return ans;
  }
};

#endif //CPP_0017__SOLUTION1_H_

//
// Created by ooooo on 2020/2/17.
//
#ifndef CPP_0139__SOLUTION1_H_
#define CPP_0139__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

/**
 * 超时
 */
class Solution {
 public:

  unordered_set<string> word_set;
  set<int> count_set;

  bool help(string s) {
    if (s.empty()) return true;
    for (auto &count: count_set) {
      string s1 = s.substr(0, count);
      if (word_set.count(s1) && help(s.substr(count, s.size() - count))) return true;
    }
    return false;
  }

  bool wordBreak(string s, vector<string> &wordDict) {
    for (auto &word: wordDict) {
      word_set.insert(word);
      count_set.insert(word.size());
    }
    return help(s);
  }
};

#endif //CPP_0139__SOLUTION1_H_

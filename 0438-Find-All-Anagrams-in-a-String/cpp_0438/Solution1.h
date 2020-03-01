//
// Created by ooooo on 2020/3/1.
//
#ifndef CPP_0438__SOLUTION1_H_
#define CPP_0438__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * timeout
 */
class Solution {
 public:

  bool is_valid(string &s, int begin, int end, unordered_map<char, int> p_map) {
    while (begin <= end) {
      char c = s[begin];
      if (p_map[c]) {
        --p_map[c];
      } else {
        return false;
      }
      ++begin;
    }
    return true;
  }

  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> p_map;
    for (auto &c: p) ++p_map[c];
    int n = p.size();
    vector<int> ans;
    for (int i = 0, len = s.size(); i <= len - n; ++i) {
      if (is_valid(s, i, i + n - 1, p_map)) ans.push_back(i);
    }
    return ans;
  }
};

#endif //CPP_0438__SOLUTION1_H_

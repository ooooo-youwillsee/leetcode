//
// Created by ooooo on 2020/3/1.
//
#ifndef CPP_0438__SOLUTION2_H_
#define CPP_0438__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 *  滑动窗口
 */
class Solution {
 public:

  unordered_map<char, int> window, needs;
  vector<int> findAnagrams(string s, string p) {
    if (p.size() > s.size()) return {};
    int l = 0, r = 0, match = 0;
    for (auto &c: p) ++needs[c];
    vector<int> ans;
    while (r < s.size()) {
      char c = s[r++];
      if (needs.count(c)) {
        window[c]++;
        if (window[c] == needs[c]) match++;
      }
      while (match == needs.size()) {
        if (r - l == p.size()) ans.push_back(l);
        c = s[l++];
        if (needs.count(c)) {
          window[c]--;
          if (window[c] < needs[c]) match--;
        }
      }
    }
    return ans;
  }
};

#endif //CPP_0438__SOLUTION2_H_

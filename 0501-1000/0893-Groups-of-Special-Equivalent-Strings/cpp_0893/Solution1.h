//
// Created by ooooo on 2020/2/1.
//
#ifndef CPP_0893__SOLUTION1_H_
#define CPP_0893__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 *
 */
class Solution {
 public:
  int numSpecialEquivGroups(vector<string> &A) {
    unordered_set<string> set;
    for (auto &s:A) {
      string odd = "", even = "";
      for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0) even.push_back(s[i]);
        else odd.push_back(s[i]);
      }
      sort(odd.begin(), odd.end());
      sort(even.begin(), even.end());
      set.insert(odd + even);
    }
    return set.size();
  }
};

#endif //CPP_0893__SOLUTION1_H_

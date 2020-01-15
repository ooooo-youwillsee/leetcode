//
// Created by ooooo on 2020/1/15.
//
#ifndef CPP_1207__SOLUTION1_H_
#define CPP_1207__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> m;
    unordered_set<int> s;
    for_each(arr.begin(), arr.end(), [&m](int x) { m[x]++; });
    for (auto &entry: m) {
      if (s.count(entry.second)) return false;
      s.insert(entry.second);
    }
    return true;
  }
};

#endif //CPP_1207__SOLUTION1_H_

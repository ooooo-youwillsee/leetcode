//
// Created by ooooo on 2020/1/15.
//
#ifndef CPP_1189__SOLUTION2_H_
#define CPP_1189__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  // balloon
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> m = {
        {'b', 0}, {'a', 0}, {'l', 0},
        {'o', 0}, {'n', 0}
    };
    for (auto &item: text) {
      if (m.count(item)) m[item]++;
    }
    m['o'] /= 2;
    m['l'] /= 2;
    int ans = INT_MAX;
    vector<int > vec;
    for_each(m.begin(), m.end(), [&ans](auto entry) { ans = min(ans, entry.second); });
    return ans;
  }
};

#endif //CPP_1189__SOLUTION2_H_

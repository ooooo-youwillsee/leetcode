//
// Created by ooooo on 2020/1/12.
//
#ifndef CPP_0575__SOLUTION1_H_
#define CPP_0575__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int distributeCandies(vector<int> &candies) {
    unordered_map<int, int> m, ans;
    int target = candies.size() / 2;
    for (const auto &candy: candies) {
      m[candy]++;
    }

    for (auto &entry: m) {
      if (entry.second == 1) {
        ans[entry.first] = entry.second;
        entry.second = 0;
      }
    }

    // 单个糖果的数量已经超过一半
    if (ans.size() >= target) {
      return target;
    }

    int c = ans.size();
    while (c != target) {
      for (auto &entry: m) {
        if (c == target) break;
        if (entry.second) {
          ans[entry.first]++;
          entry.second--;
          c++;
        }
      }
    }

    return ans.size();

  }
};

#endif //CPP_0575__SOLUTION1_H_

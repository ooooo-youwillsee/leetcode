//
// Created by ooooo on 2020/1/12.
//
#ifndef CPP_0594__SOLUTION2_H_
#define CPP_0594__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 哈希表 +  单次扫描
 */
class Solution {
 public:
  int findLHS(vector<int> &nums) {
    unordered_map<int, int> m;
    int ans = 0;
    for (const auto &num: nums) {
      m[num]++;
      if (m.count(num - 1)) {
        ans = max(ans, m[num] + m[num - 1]);
      }
      if (m.count(num + 1)) {
        ans = max(ans, m[num] + m[num + 1]);
      }
    }
    return ans;
  }
};

#endif //CPP_0594__SOLUTION2_H_

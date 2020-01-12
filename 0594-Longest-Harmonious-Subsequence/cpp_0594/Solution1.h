//
// Created by ooooo on 2020/1/12.
//
#ifndef CPP_0594__SOLUTION1_H_
#define CPP_0594__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 哈希表
 */
class Solution {
 public:
  int findLHS(vector<int> &nums) {
    int ans = 0;
    unordered_map<int, int> m;
    for (const auto &num: nums) {
      m[num]++;
    }

    // 不能在下面的for循环中使用m[k], 如果元素k不存在，就修改m.size()
    for (const auto &entry: m) {
      int c = 0;
      if (m.count(entry.first - 1)) {
        c = m[entry.first - 1];
      }
      if (m.count(entry.first + 1)) {
        c = max(c, m[entry.first + 1]);
      }
      // c为0，表示没有差为1的元素
      if (c == 0) continue;
      ans = max(c + entry.second, ans);
    }

    return ans;
  }
};

#endif //CPP_0594__SOLUTION1_H_

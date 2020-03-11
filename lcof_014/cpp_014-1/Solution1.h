//
// Created by ooooo on 2020/3/11.
//
#ifndef CPP_014_1__SOLUTION1_H_
#define CPP_014_1__SOLUTION1_H_

#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * dfs + memo
 */
class Solution {
 public:

  /**
   * @param flag  false 表示不能切
   * @return
   */
  int dfs(int l, int r, bool flag) {
    if (memo.count(r - l)) return memo[r - l];
    if (l + 1 == r) return 1;
    int ans = !flag ? 1 : r - l;
    for (int i = l + 1; i < r; ++i) {
      ans = max(ans, dfs(l, i, true) * dfs(i, r, true));
    }
    return memo[r - l] = ans;
  }

  unordered_map<int, int> memo;

  int cuttingRope(int n) {
    return dfs(0, n, false);
  }
};
#endif //CPP_014_1__SOLUTION1_H_

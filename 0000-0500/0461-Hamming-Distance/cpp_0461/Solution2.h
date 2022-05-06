//
// Created by ooooo on 2020/2/6.
//
#ifndef CPP_0461__SOLUTION2_H_
#define CPP_0461__SOLUTION2_H_

#include <iostream>
#include <sstream>

using namespace std;

/**
 * ^操作， i & (i-1) --> 去掉最后一个1
 */
class Solution {
 public:

  int hammingDistance(int x, int y) {
    int res = x ^y, ans = 0;
    while (res) {
      ans += 1;
      res = res & (res - 1);
    }
    return ans;
  }
};

#endif //CPP_0461__SOLUTION2_H_

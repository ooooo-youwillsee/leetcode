//
// Created by ooooo on 2020/1/30.
//
#ifndef CPP_0788__SOLUTION2_H_
#define CPP_0788__SOLUTION2_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:

  bool valid(int v) {
    bool valid = false;
    while (v) {
      int mod = v % 10;
      if (mod == 3 || mod == 4 || mod == 7) return false;
        // 有一个数字可以旋转， 说明是有效的
      else if (mod == 2 || mod == 5 || mod == 6 || mod == 9) valid = true;
      v /= 10;
    }
    return valid;
  }

  int rotatedDigits(int N) {
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
      if (valid(i)) ans++;
    }
    return ans;
  }
};

#endif //CPP_0788__SOLUTION2_H_

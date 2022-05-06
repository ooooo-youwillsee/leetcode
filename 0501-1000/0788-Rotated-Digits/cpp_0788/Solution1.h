//
// Created by ooooo on 2020/1/30.
//
#ifndef CPP_0788__SOLUTION1_H_
#define CPP_0788__SOLUTION1_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:

  unordered_map<int, int> map = {
      {0, 0}, {1, 1}, {8, 8},
      {2, 5}, {5, 2}, {6, 9}, {9, 6},
      {3, -1}, {4, -1}, {7, -1}
  };

  bool valid(int v) {
    int sum = 0, num = v;
    int count = 0;
    while (v) {
      int mod = v % 10;
      if (map[mod] == -1) return false;
      sum += pow(10, count) * map[mod];
      v /= 10;
      count++;
    }
    return sum != num;
  }

  int rotatedDigits(int N) {
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
      if (valid(i)) ans++;
    }
    return ans;
  }
};

#endif //CPP_0788__SOLUTION1_H_

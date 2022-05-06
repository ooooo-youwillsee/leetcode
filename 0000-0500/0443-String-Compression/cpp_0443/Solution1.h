//
// Created by ooooo on 2020/1/26.
//
#ifndef CPP_0443__SOLUTION1_H_
#define CPP_0443__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * loop 相邻两项比较
 */
class Solution {
 public:
  int compress(vector<char> &chars) {
    int count = 1, ans = 0;
    for (int i = 0; i < chars.size(); ++i) {
      // 相邻的两项比较可以在这里判断
      if (i == chars.size() - 1 || chars[i] != chars[i + 1]) {
        chars[ans++] = chars[i];
        if (count > 1) {
          for (auto c: to_string(count)) {
            chars[ans++] = c;
          }
        }
        count = 1;
      } else {
        count++;
      }
    }
    return ans;
  }
};

#endif //CPP_0443__SOLUTION1_H_

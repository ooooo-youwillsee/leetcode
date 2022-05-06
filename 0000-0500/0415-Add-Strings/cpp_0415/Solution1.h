//
// Created by ooooo on 2020/1/25.
//
#ifndef CPP_0415__SOLUTION1_H_
#define CPP_0415__SOLUTION1_H_

#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  string addStrings(string num1, string num2) {
    string ans = "";
    int c1, c2, more = 0;
    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; --i, --j) {
      c1 = i < 0 ? 0 : num1[i] - '0';
      c2 = j < 0 ? 0 : num2[j] - '0';
      // % -> 余数
      int a = (c1 + c2 + more) % 10;
      // / -> 进位
      more = (c1 + c2 + more) / 10;
      ans += to_string(a);
    }
    if (more) ans += to_string(more);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

#endif //CPP_0415__SOLUTION1_H_

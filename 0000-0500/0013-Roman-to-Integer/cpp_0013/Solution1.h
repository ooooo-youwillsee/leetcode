//
// Created by ooooo on 2020/1/24.
//
#ifndef CPP_0013__SOLUTION1_H_
#define CPP_0013__SOLUTION1_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  unordered_map<char, int> m = {
      {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
      {'C', 100}, {'D', 500}, {'M', 1000}
  };
  unordered_map<string, int> m2 = {
      {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90},
      {"CD", 400}, {"CM", 900}
  };

  int romanToInt(string s) {
    int ans = 0;
    for (int i = 0; i < s.length();) {
      // 索引i不是最后一个字符，取两个字符判断
      if (i != s.length() - 1 && m2.count(s.substr(i, 2))) {
        ans += m2[s.substr(i, 2)];
        i += 2;
        continue;
      }
      ans += m[s[i]];
      i += 1;
    }
    return ans;
  }
};

#endif //CPP_0013__SOLUTION1_H_

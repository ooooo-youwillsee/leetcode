//
// Created by ooooo on 2020/1/15.
//
#ifndef CPP_1189__SOLUTION1_H_
#define CPP_1189__SOLUTION1_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    unordered_map<char, int> m;
    for_each(text.begin(), text.end(), [&m](char x) { m[x]++; });
    int ans = 0;
    string target = "balloon";
    while (true) {
      bool notFound = false;
      for (auto &c: target) {
        if (!m[c]) {
          notFound = true;
          break;
        }
        --m[c];
      }
      if (notFound) break;
      ans++;
    }
    return ans;
  }
};

#endif //CPP_1189__SOLUTION1_H_

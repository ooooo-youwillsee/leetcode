//
// Created by ooooo on 2020/1/25.
//
#ifndef CPP_0383__SOLUTION1_H_
#define CPP_0383__SOLUTION1_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> m1, m2;
    for (auto c: ransomNote) {
      ++m1[c];
    }
    for (auto c: magazine) {
      ++m2[c];
    }

    for (auto entry: m1) {
      if (m2[entry.first] < entry.second) return false;
    }
    return true;
  }
};

#endif //CPP_0383__SOLUTION1_H_

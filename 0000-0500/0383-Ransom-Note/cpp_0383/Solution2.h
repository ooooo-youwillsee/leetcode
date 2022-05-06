//
// Created by ooooo on 2020/1/25.
//
#ifndef CPP_0383__SOLUTION2_H_
#define CPP_0383__SOLUTION2_H_

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.size() > magazine.size()) return false;
    int arr[26] = {0};
    for (auto c: magazine) {
      ++arr[c - 'a'];
    }
    for (auto c: ransomNote) {
      if (arr[c - 'a'] == 0) return false;
      --arr[c - 'a'];
    }
    return true;
  }
};

#endif //CPP_0383__SOLUTION2_H_

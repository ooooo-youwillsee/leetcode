//
// Created by ooooo on 2020/1/31.
//
#ifndef CPP_0859__SOLUTION1_H_
#define CPP_0859__SOLUTION1_H_

#include <iostream>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
 public:

  string simplify(string s) {
    stringstream ss;
    bool added = true;
    ss << s[0];
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        ss << s[i];
      }
    }
    return ss.str();
  }

  bool buddyStrings(string A, string B) {
    if (A.size() != B.size() || A.empty() || B.empty()) return false;
    string simpleA = simplify(A);
    string simpleB = simplify(B);
    unordered_set<char> set;
    int left = 0, right = simpleA.size() - 1, len = simpleA.size();
    while (left < len && simpleA[left] == simpleB[left]) {
      set.insert(simpleA[left]);
      left++;
    }
    // 全部字符都相同, 有重复字符串就可以交换
    if (left == len) return simpleA.size() != A.size() || set.size() != simpleA.size();
    while (right >= 0 && simpleA[right] == simpleB[right]) {
      right--;
    }
    // 不同的位置一样，无法交换
    if (left == right) return false;
    return simpleA[left] == simpleB[right] && simpleA[right] == simpleB[left];
  }
};

#endif //CPP_0859__SOLUTION1_H_

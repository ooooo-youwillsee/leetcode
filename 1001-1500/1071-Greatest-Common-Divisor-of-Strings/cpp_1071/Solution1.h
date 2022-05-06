//
// Created by ooooo on 2020/2/2.
//
#ifndef CPP_1071__SOLUTION1_H_
#define CPP_1071__SOLUTION1_H_

#include <iostream>

using namespace std;

/**
 * 暴力法
 */
class Solution {
 public:

  // a % b
  bool div(string a, string b) {
    if (a.size() % b.size() != 0) return false;
    for (int i = 0; i < a.size(); i += b.size()) {
      if (a.substr(i, b.size()) != b) return false;
    }
    return true;
  }

  string gcdOfStrings(string str1, string str2) {
    string min_str = "", max_str = "";
    if (str1.size() < str2.size()) {
      min_str = str1;
      max_str = str2;
    } else {
      min_str = str2;
      max_str = str1;
    }
    if (max_str.find(min_str) == -1) return "";
    for (int i = min_str.size(); i > 0; i--) {
      string target_str = min_str.substr(0, i);
      if (div(min_str, target_str) && div(max_str, target_str)) return target_str;
    }
    return "";
  }
};

#endif //CPP_1071__SOLUTION1_H_

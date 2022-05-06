//
// Created by ooooo on 2020/4/1.
//
#ifndef CPP_045__SOLUTION1_H_
#define CPP_045__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * 和 leetcode 不一样
 */
class Solution {
 public:

  bool static compareTo(string &s1, string &s2) {
    int len1 = s1.size(), len2 = s2.size();
    for (int i = 0, j = 0; i < len1 || j < len2;) {
      if (i == len1) {
        return s2[i] > s1[0];
      }
      if (j == len2) {
        return s1[i] < s2[0];
      }
      if (s1[i] == s2[j]) {
        i++;
        j++;
      } else return s1[i] < s2[j];
    }
    return true;
  }

  string minNumber(vector<int> &nums) {
    vector<string> vec;
    for (auto &num: nums) vec.push_back(to_string(num));
    sort(vec.begin(), vec.end(), compareTo);
    stringstream ss;
    for (auto &str: vec) {
      ss << str;
    }
    return ss.str();
  }
};

#endif //CPP_045__SOLUTION1_H_

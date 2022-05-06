//
// Created by ooooo on 2020/4/1.
//
#ifndef CPP_045__SOLUTION2_H_
#define CPP_045__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * ab < ba
 */
class Solution {
 public:

  string minNumber(vector<int> &nums) {
    vector<string> vec;
    for (auto &num: nums) vec.push_back(to_string(num));
    sort(vec.begin(), vec.end(), [](string &s1, string s2) {
      return s1 + s2 < s2 + s1;
    });
    stringstream ss;
    for (auto &str: vec) {
      ss << str;
    }
    return ss.str();
  }
};

#endif //CPP_045__SOLUTION2_H_

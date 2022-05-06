//
// Created by ooooo on 2020/1/11.
//
#ifndef CPP_0389__SOLUTION3_H_
#define CPP_0389__SOLUTION3_H_

#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 位运算  a^a = 0 ;  a^0=a  最快
 */
class Solution {
 public:
  char findTheDifference(string s, string t) {
    s += t;
    int ch = 0;
    for (auto &c: s) {
      ch ^= c;
    }
    return ch;
  }
};

#endif //CPP_0389__SOLUTION3_H_

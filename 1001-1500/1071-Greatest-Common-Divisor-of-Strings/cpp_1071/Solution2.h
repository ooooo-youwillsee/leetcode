//
// Created by ooooo on 2020/2/2.
//
#ifndef CPP_1071__SOLUTION2_H_
#define CPP_1071__SOLUTION2_H_

#include <iostream>
#include <math.h>
#include <numeric>

using namespace std;

/**
 * gcd
 */
class Solution {
 public:

  string gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) return "";
    return str1.substr(0, gcd(str1.size(), str2.size()));
  }
};

#endif //CPP_1071__SOLUTION2_H_

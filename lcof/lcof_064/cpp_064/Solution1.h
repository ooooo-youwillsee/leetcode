//
// Created by ooooo on 2020/4/21.
//
#ifndef CPP_064__SOLUTION1_H_
#define CPP_064__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  int sumNums(int n) {
    bool f = n > 1 && (n += sumNums(n - 1));
    return n;
  }
};

#endif //CPP_064__SOLUTION1_H_

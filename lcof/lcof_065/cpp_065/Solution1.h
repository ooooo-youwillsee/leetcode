//
// Created by ooooo on 2020/4/23.
//
#ifndef CPP_065__SOLUTION1_H_
#define CPP_065__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  int add(int a, int b) {
    int num1 = 0, num2 = 0;
    do {
      num1 = a ^ b; // 不进位
      num2 = (unsigned int) (a & b) << 1; // 进1
      a = num1;
      b = num2;
    } while (num2 != 0);

    return num1;
  }
};

#endif //CPP_065__SOLUTION1_H_

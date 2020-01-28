//
// Created by ooooo on 2020/1/28.
//
#ifndef CPP_0657__SOLUTION1_H_
#define CPP_0657__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  bool judgeCircle(string moves) {
    int i = 0, j = 0;
    for (auto move: moves) {
      if (move == 'U') i++;
      else if(move == 'D') i--;
      else if (move == 'R') j++;
      else j--;
    }
    return i == 0 && j == 0;
  }
};

#endif //CPP_0657__SOLUTION1_H_

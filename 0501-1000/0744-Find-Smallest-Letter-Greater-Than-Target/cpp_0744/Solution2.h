//
// Created by ooooo on 2020/1/20.
//
#ifndef CPP_0744__SOLUTION2_H_
#define CPP_0744__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 *  loop
 */
class Solution {
 public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    for (auto c: letters) {
      if (c > target) return c;
    }
    return letters[0];
  }
};
#endif //CPP_0744__SOLUTION2_H_

//
// Created by ooooo on 2020/4/6.
//
#ifndef CPP_049__SOLUTION1_H_
#define CPP_049__SOLUTION1_H_

#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * timeout
 */
class Solution {
 public:
  int nthUglyNumber(int n) {
    unordered_set<int> s{1, 2, 3, 5};
    for (int i = 1; i < INT_MAX; ++i) {
      if (i == 1) n--;
      else {
        bool has = false;
        if (i % 2 == 0 && s.count(i / 2)) has = true;
        else if (i % 3 == 0 && s.count(i / 3)) has = true;
        else if (i % 5 == 0 && s.count(i / 5)) has = true;
        if (has) {
          s.insert(i);
          n--;
        }
      }
      if (n == 0) return i;
    }
    return -1;
  }
};

#endif //CPP_049__SOLUTION1_H_

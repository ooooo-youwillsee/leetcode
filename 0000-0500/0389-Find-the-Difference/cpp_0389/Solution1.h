//
// Created by ooooo on 2020/1/11.
//
#ifndef CPP_0389__SOLUTION1_H_
#define CPP_0389__SOLUTION1_H_

#include <iostream>

using namespace std;

/**
 * sort
 */
class Solution {
 public:
  char findTheDifference(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != t[i]) return t[i];
    }
    return t[t.size() - 1];
  }
};

#endif //CPP_0389__SOLUTION1_H_

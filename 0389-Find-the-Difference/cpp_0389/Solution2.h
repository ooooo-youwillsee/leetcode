//
// Created by ooooo on 2020/1/11.
//
#ifndef CPP_0389__SOLUTION2_H_
#define CPP_0389__SOLUTION2_H_

#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * map
 */
class Solution {
 public:
  char findTheDifference(string s, string t) {
    unordered_map<char, int> m;
    for (auto &c:s) {
      m[c]++;
    }

    for (int i = 0; i < t.size(); ++i) {
      if (m[t[i]]) {
        m[t[i]]--;
      } else return t[i];
    }
    return '\0';
  }
};

#endif //CPP_0389__SOLUTION2_H_

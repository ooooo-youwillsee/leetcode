//
// Created by ooooo on 2020/1/15.
//
#ifndef CPP_0771__SOLUTION1_H_
#define CPP_0771__SOLUTION1_H_

#include <iostream>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
 public:
  int numJewelsInStones(string J, string S) {
    unordered_set<char> s(J.begin(), J.end());
    return accumulate(S.begin(), S.end(), 0, [&](int x, int y) { return s.count(y) ? x + 1 : x; });
  }
};

#endif //CPP_0771__SOLUTION1_H_

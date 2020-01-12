//
// Created by ooooo on 2020/1/12.
//
#ifndef CPP_0575__SOLUTION2_H_
#define CPP_0575__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int distributeCandies(vector<int> &candies) {
    unordered_set<int> ans(candies.begin(), candies.end());
    return min(ans.size(), candies.size() / 2);
  }
};

#endif //CPP_0575__SOLUTION2_H_

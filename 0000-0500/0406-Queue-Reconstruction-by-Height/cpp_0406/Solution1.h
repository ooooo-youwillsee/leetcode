//
// Created by ooooo on 2020/2/29.
//
#ifndef CPP_0406__SOLUTION1_H_
#define CPP_0406__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
      return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
    });
    vector<vector<int>> ans;
    for (int i = 0; i < people.size(); ++i) {
      ans.insert(ans.begin() + people[i][1], people[i]);
    }
    return ans;
  }
};

#endif //CPP_0406__SOLUTION1_H_

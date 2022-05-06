//
// Created by ooooo on 2020/1/12.
//
#ifndef CPP_0599__SOLUTION1_H_
#define CPP_0599__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    unordered_map<string, int> m;
    vector<string> ans;
    int min = INT_MAX;
    for (int i = 0; i < list1.size(); ++i) {
      m[list1[i]] = i;
    }
    for (int i = 0; i < list2.size(); ++i) {
      if (m.count(list2[i])) {
        int sum = i + m[list2[i]];
        if (sum < min) {
          // 新的最小索引值
          ans.clear();
          min = sum;
          ans.push_back(list2[i]);
        } else if (sum == min) {
          ans.push_back(list2[i]);
        }
      }
    }

    return ans;
  }
};

#endif //CPP_0599__SOLUTION1_H_

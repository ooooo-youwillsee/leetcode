//
// Created by ooooo on 2020/1/13.
//
#ifndef CPP_0690__SOLUTION1_H_
#define CPP_0690__SOLUTION1_H_

#include "Employee.h"
#include <unordered_map>

/**
 * loop
 */
class Solution {
 public:
  int getImportance(vector<Employee *> employees, int id) {
    unordered_map<int, int> importanceMap;
    unordered_map<int, vector<int>> subordinateMap;
    for (const auto &item: employees) {
      importanceMap[item->id] = item->importance;
      subordinateMap[item->id] = item->subordinates;
    }

    int ans = importanceMap[id];
    vector<int> subIds = subordinateMap[id];
    while (!subIds.empty()) {
      // 用于添加每一个直属下级
      vector<int> vec;
      for (auto &subId: subIds) {
        ans += importanceMap[subId];
        vec.insert(vec.end(), subordinateMap[subId].begin(), subordinateMap[subId].end());
      }
      subIds = vec;
    }
    return ans;
  }
};

#endif //CPP_0690__SOLUTION1_H_

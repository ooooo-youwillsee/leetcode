//
// Created by ooooo on 2020/1/13.
//
#ifndef CPP_0690__SOLUTION2_H_
#define CPP_0690__SOLUTION2_H_

#include "Employee.h"
#include <unordered_map>


/**
 * dfs
 */
class Solution {
 public:

  int dfs(int id, unordered_map<int, Employee *> &map) {
    int sum = map[id]->importance;
    for (const auto &subId: map[id]->subordinates) {
      sum += dfs(subId, map);
    }
    return sum;
  }

  int getImportance(vector<Employee *> employees, int id) {
    unordered_map<int, Employee *> map;
    for (const auto &item: employees) {
      map[item->id] = item;
    }

    return dfs(id, map);
  }
};

#endif //CPP_0690__SOLUTION2_H_

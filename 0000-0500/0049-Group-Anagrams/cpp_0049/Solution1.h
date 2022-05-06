//
// Created by ooooo on 2020/2/11.
//
#ifndef CPP_0049__SOLUTION1_H_
#define CPP_0049__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 哈希表
 */
class Solution {
 public:

  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> map;
    for (int i = 0; i < strs.size(); ++i) {
      string key = string(strs[i]);
      sort(key.begin(), key.end());
      map[key].push_back(strs[i]);
    }

    vector<vector<string>> ans;
    for (auto &entry: map) {
      ans.push_back(entry.second);
    }
    return ans;
  }
};

#endif //CPP_0049__SOLUTION1_H_

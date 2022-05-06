//
// Created by ooooo on 2020/1/16.
//
#ifndef CPP_1160__SOLUTION1_H_
#define CPP_1160__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int countCharacters(vector<string> &words, string chars) {
    unordered_map<char, int> m;
    for_each(chars.begin(), chars.end(), [&m](char c) { m[c]++; });
    int ans = 0;
    for (auto &item: words) {
      unordered_map<char, int> wordMap;
      for_each(item.begin(), item.end(), [&wordMap](char c) { wordMap[c]++; });
      bool find = true;
      for (auto &entry: wordMap) {
        if (m[entry.first] < entry.second) {
          find = false;
          break;
        }
      }
      if (find) {
        ans += item.size();
      }
    }
    return ans;
  }
};

#endif //CPP_1160__SOLUTION1_H_

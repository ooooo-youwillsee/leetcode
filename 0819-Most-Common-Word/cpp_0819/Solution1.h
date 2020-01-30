//
// Created by ooooo on 2020/1/30.
//
#ifndef CPP_0819__SOLUTION1_H_
#define CPP_0819__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <regex>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * timeout ???
 */
class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string> &banned) {
    unordered_map<string, int> m;
    unordered_set<string> bannedSet(banned.begin(), banned.end());
    regex reg("[A-Za-z]+");
    for (int i = 0; i < paragraph.size(); ++i) {
      paragraph[i] = tolower(paragraph[i]);
    }
    for (regex_iterator it(paragraph.begin(), paragraph.end(), reg); it->begin() < it->end(); ++it) {
      if (bannedSet.count(it->str())) continue;
      ++m[it->str()];
    }
    int max = 0;
    string ans;
    for (auto entry: m) {
      if (entry.second > max) {
        ans = entry.first;
        max = entry.second;
      }
    }
    return ans;
  }
};

#endif //CPP_0819__SOLUTION1_H_

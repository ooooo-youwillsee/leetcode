//
// Created by ooooo on 2020/1/14.
//
#ifndef CPP_0748__SOLUTION1_H_
#define CPP_0748__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:

  bool check(string word, unordered_map<char, int> &m) {
    unordered_map<char, int> wordMap;
    for (const auto &c: word) wordMap[c]++;
    for (const auto &entry :m) {
      if (entry.second > wordMap[entry.first]) return false;
    }
    return true;
  }

  string shortestCompletingWord(string licensePlate, vector<string> &words) {
    unordered_map<char, int> m;
    for (const auto &item: licensePlate) {
      char c = tolower(item);
      if (c >= 'a' && c <= 'z') m[c]++;
    }

    int index = INT_MAX;
    string ans = "";
    for (int i = 0; i < words.size(); ++i) {
      if (check(words[i], m)) {
        if (ans.empty() || words[i].size() < ans.size()
            || (words[i].size() == ans.size() && i < index)) {
          ans = words[i];
          index = i;
        }
      }
    }
    return ans;
  }
};

#endif //CPP_0748__SOLUTION1_H_

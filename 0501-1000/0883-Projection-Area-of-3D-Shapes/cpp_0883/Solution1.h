//
// Created by ooooo on 2020/1/15.
//
#ifndef CPP_0883__SOLUTION1_H_
#define CPP_0883__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 计数 等于一次的单词
 */
class Solution {

 public:

  vector<string> split(string s) {
    vector<string> ans;
    s += " ";
    int i = 0;
    int j = s.find_first_of(" ", i);
    while (j != -1) {
      ans.push_back(s.substr(i, j - i));
      i = j + 1;
      j = s.find_first_of(" ", i);
    }
    return ans;
  }

  vector<string> uncommonFromSentences(string A, string B) {
    unordered_map<string, int> m;
    for (auto &word: split(A)) {
      m[word]++;
    }
    for (auto &word: split(B)) {
      m[word]++;
    }

    vector<string> ans;
    for (auto &entry: m) {
      if (entry.second ==1) ans.push_back(entry.first);
    }
    return ans;
  }
};

#endif //CPP_0883__SOLUTION1_H_

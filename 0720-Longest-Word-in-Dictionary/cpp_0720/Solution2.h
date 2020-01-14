//
// Created by ooooo on 2020/1/14.
//
#ifndef CPP_0720__SOLUTION2_H_
#define CPP_0720__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 哈希表
 */
class Solution {
 public:

  bool check(string word, unordered_set<string> &s) {
    for (int i = word.size(); i >= 1; --i) {
      if (!s.count(word.substr(0, i))) return false;
    }
    return true;
  }

  string longestWord(vector<string> &words) {
    unordered_map<int, vector<string>> m;
    unordered_set<string> s;
    int maxLen = INT_MIN;
    for (const auto &word: words) {
      s.insert(word);
      int len = word.size();
      maxLen = max(maxLen, len);
      if (m.count(len)) {
        m[len].push_back(word);
      } else {
        m[len] = {word};
      }
    }

    for (int i = maxLen; i > 0; --i) {
      string ans = "";
      for (auto &word: m[i]) {
        if (check(word, s) && (ans.size() < word.size() || (ans.size() == word.size() && ans > word))) {
          ans = word;
        }
      }
      if (!ans.empty()) return ans;
    }
    return "";
  }
};

#endif //CPP_0720__SOLUTION2_H_

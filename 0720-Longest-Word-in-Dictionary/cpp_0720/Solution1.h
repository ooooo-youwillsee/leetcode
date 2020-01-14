//
// Created by ooooo on 2020/1/14.
//
#ifndef CPP_0720__SOLUTION1_H_
#define CPP_0720__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 超时
 */
class Solution {
 public:

  string ans = "";

  void dfs(string s, int len, unordered_map<int, vector<string>> m) {
    vector<string> words = m[len];
    if (words.empty()) {
      // 不满足关系说明已经查找完毕 和ans作比较
      if (ans.size() < s.size()) {
        ans = s;
      } else if (ans.size() == s.size() && s < ans) {
        ans = s;
      }
      return;
    }
    for (int i = 0; i < words.size(); ++i) {
      if (s == words[i].substr(0, len - 1)) {
        dfs(words[i], len + 1, m);
      } else {
        // 不满足关系说明已经查找完毕 和ans作比较
        if (ans.size() < s.size()) {
          ans = s;
        } else if (ans.size() == s.size() && s < ans) {
          ans = s;
        }
      }
    }
  }

  string longestWord(vector<string> &words) {
    unordered_map<int, vector<string>> m;
    for (const auto &word: words) {
      int len = word.size();
      if (m.count(len)) {
        m[len].push_back(word);
      } else {
        m[len] = {word};
      }
    }
    dfs("", 1, m);
    return ans;
  }
};

#endif //CPP_0720__SOLUTION1_H_

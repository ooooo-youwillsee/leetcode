//
// Created by ooooo on 2020/1/16.
//
#ifndef CPP_0953__SOLUTION1_H_
#define CPP_0953__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool check(string s1, string s2, int m[]) {
    // 比较最小的长度
    for (int i = 0; i < min(s1.size(), s2.size()); ++i) {
      int j = m[s1[i] - 'a'], k = m[s2[i] - 'a'];
      if (j == k) continue;
        // 只比较第一个不相同的值
      else return j < k;
    }
    return s1.size() <= s2.size();
  }

  bool isAlienSorted(vector<string> &words, string order) {
    int m[26] = {0};
    for (int i = 0; i < order.size(); ++i) {
      m[order[i] - 'a'] = i;
    }
    for (int i = 0; i < words.size() - 1; ++i) {
      if (!check(words[i], words[i + 1], m)) return false;
    }
    return true;
  }
};

#endif //CPP_0953__SOLUTION1_H_

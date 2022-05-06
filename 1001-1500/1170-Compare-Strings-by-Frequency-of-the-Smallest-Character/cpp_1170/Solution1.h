//
// Created by ooooo on 2020/2/2.
//
#ifndef CPP_1170__SOLUTION1_H_
#define CPP_1170__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {

 public:
  int countFreq(string &s) {
    char c = s[0];
    int count = 1;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] < c) {
        count = 1;
        c = s[i];
      } else if (s[i] == c) count += 1;
    }
    return count;
  }

  vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
    vector<int> ans, counts;
    for (auto &word: words) {
      counts.push_back(countFreq(word));
    }
    sort(counts.begin(), counts.end(), greater<int>());
    for (int i = 0; i < queries.size(); ++i) {
      int res = countFreq(queries[i]);
      int j = 0; // 计数
      for (auto count: counts) {
        if (count > res) j += 1;
        else break;
      }
      ans.push_back(j);
    }
    return ans;
  }
};

#endif //CPP_1170__SOLUTION1_H_

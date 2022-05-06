//
// Created by ooooo on 2020/1/16.
//
#ifndef CPP_1002__SOLUTION1_H_
#define CPP_1002__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<string> commonChars(vector<string> &A) {
    vector<unordered_map<char, int>> wordMaps(A.size());
    for (int i = 0; i < A.size(); ++i) {
      for (auto &c: A[i]) {
        wordMaps[i][c]++;
      }
    }

    vector<string> ans;
    for (auto &c: A[0]) {
      bool find = true;
      for (auto &m: wordMaps) {
        if (!m[c]) {
          find = false;
          break;
        }
        m[c]--;
      }
      if (find) {
        ans.push_back(string(1, c));
      }
    }
    return ans;
  }
};

#endif //CPP_1002__SOLUTION1_H_

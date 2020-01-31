//
// Created by ooooo on 2020/1/31.
//
#ifndef CPP_0859__SOLUTION2_H_
#define CPP_0859__SOLUTION2_H_

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
 public:

  bool buddyStrings(string A, string B) {
    if (A.size() != B.size() || A.empty() || B.empty()) return false;
    if (A == B) {
      unordered_set<char> set(26);
      for (auto &c: A) {
        set.insert(c);
      }
      // 有重复字符
      return set.size() != A.size();
    } else {
      int swap_one = -1, swap_second = -1;
      for (int i = 0; i < A.size(); ++i) {
        if (A[i] != B[i]) {
          if (swap_one == -1) swap_one = i;
          else if (swap_second == -1) swap_second = i;
          else return false;
        }
      }
      return swap_second != -1 && A[swap_one] == B[swap_second] && A[swap_second] == B[swap_one];
    }
  }
};

#endif //CPP_0859__SOLUTION2_H_

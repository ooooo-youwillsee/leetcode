//
// Created by ooooo on 2020/4/5.
//
#ifndef CPP_048__SOLUTION1_H_
#define CPP_048__SOLUTION1_H_

#include <iostream>
using namespace std;

/**
 * 滑动窗口
 */
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0, ans = 0;
    bool arr[256] = {false};
    while (j < s.size()) {
      if (arr[s[j]]) {
        arr[s[i]] = false;
        i++;
      } else {
        arr[s[j]] = true;
        j++;
      }
      ans = max(ans, j - i);
    }
    return ans;
  }
};

#endif //CPP_048__SOLUTION1_H_

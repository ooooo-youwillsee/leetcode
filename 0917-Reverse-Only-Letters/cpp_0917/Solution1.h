//
// Created by ooooo on 2020/2/1.
//
#ifndef CPP_0917__SOLUTION1_H_
#define CPP_0917__SOLUTION1_H_

#include <iostream>

using namespace std;

/**
 * 双指针
 */
class Solution {
 public:
  string reverseOnlyLetters(string S) {
    if (S.size() <= 1) return S;
    int left = 0, right = S.size() - 1;
    while (true) {
      while (left <= right && !isalpha(S[left])) left++;
      while (right >= left && !isalpha(S[right])) right--;
      if (left > right) break;
      swap(S[left++], S[right--]);
    }
    return S;
  }
};

#endif //CPP_0917__SOLUTION1_H_

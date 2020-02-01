//
// Created by ooooo on 2020/2/1.
//
#ifndef CPP_0917__SOLUTION2_H_
#define CPP_0917__SOLUTION2_H_

#include <iostream>

using namespace std;

/**
 * 存入数组，倒序填入原字符串
 */
class Solution {
 public:
  string reverseOnlyLetters(string S) {
    if (S.size() <= 1) return S;
    int *arr = new int[S.size()], count = 0;
    // 存入所有的字符
    for (int i = 0; i < S.size(); ++i) {
      if (isalpha(S[i])) {
        arr[count++] = S[i];
      }
    }
    // 倒序插入字符
    for (int i = 0; i < S.size(); ++i) {
      if (isalpha(S[i])) {
        S[i] = arr[--count];
      }
    }
    return S;
  }
};

#endif //CPP_0917__SOLUTION2_H_

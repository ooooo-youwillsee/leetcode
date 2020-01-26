//
// Created by ooooo on 2020/1/26.
//
#ifndef CPP_0520__SOLUTION1_H_
#define CPP_0520__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  bool detectCapitalUse(string word) {
    int i = 0;
    bool flag = false;
    for (int j = 0; j < word.size(); ++j) {
      if (isupper(word[j])) {
        i++;
        if (j == 0) flag = true;
      }
    }
    if (i == word.size() || i == 0) return true;
    else if (i == 1 && flag) return true;
    return false;
  }
};

#endif //CPP_0520__SOLUTION1_H_

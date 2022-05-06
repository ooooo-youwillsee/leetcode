//
// Created by ooooo on 2020/1/25.
//
#ifndef CPP_0058__SOLUTION1_H_
#define CPP_0058__SOLUTION1_H_

#include <iostream>

using namespace std;

/**
 * 从头遍历尾
 */
class Solution {
 public:
  int lengthOfLastWord(string s) {
    s += " ";
    string ans = "";
    int i = 0, j = s.find_first_of(" ");
    while (j != -1) {
      string word = s.substr(i, j - i);
      if (word != "") ans = word;
      i = j + 1;
      j = s.find_first_of(" ", i);
    }
    return ans.size();
  }
};

#endif //CPP_0058__SOLUTION1_H_

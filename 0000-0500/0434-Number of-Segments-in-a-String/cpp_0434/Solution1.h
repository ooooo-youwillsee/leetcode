//
// Created by ooooo on 2020/1/25.
//
#ifndef CPP_0434__SOLUTION1_H_
#define CPP_0434__SOLUTION1_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  int countSegments(string s) {
    s += " ";
    int ans = 0, i = 0, j = s.find_first_of(" ", i);
    while (j != -1) {
      string word = s.substr(i, j - i);
      if (word != "") {
        ans++;
      }
      i = j + 1;
      j = s.find_first_of(" ", i);
    }
    return ans;
  }
};

#endif //CPP_0434__SOLUTION1_H_

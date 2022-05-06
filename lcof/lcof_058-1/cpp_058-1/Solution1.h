//
// Created by ooooo on 2020/4/18.
//
#ifndef CPP_058_1__SOLUTION1_H_
#define CPP_058_1__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
 public:

  int findFirstLetter(string &s, int i) {
    for (; i < s.size(); i++) {
      if (s[i] != ' ') return i;
    }
    return -1;
  }

  string reverseWords(string s) {
    s += " ";
    vector<string> str_s;
    int i = 0, j = 0;
    while ((i = findFirstLetter(s, i)) != -1) {
      j = s.find(" ", i);
      if (j == -1) break;
      str_s.emplace_back(s.substr(i, j - i));
      i = j + 1;
    }
    stringstream ss;
    for (i = str_s.size() - 1; i >= 0; --i) {
      ss << str_s[i];
      if (i != 0) ss << " ";
    }
    return ss.str();
  }
};

#endif //CPP_058_1__SOLUTION1_H_

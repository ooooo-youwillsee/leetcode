//
// Created by ooooo on 2020/4/18.
//
#ifndef CPP_058_1__SOLUTION2_H_
#define CPP_058_1__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
 public:

  void reverse(string &s, int i, int j) {
    while (i < j) {
      char tmp = s[i];
      s[i] = s[j];
      s[j] = tmp;
      i++;
      j--;
    }
  }

  void findFirstLetter(string &s, int &i) {
    for (; i < s.size(); i++) {
      if (s[i] != ' ') break;
    }
  }

  string reverseWords(string s) {
    int i = 0;
    string ss;
    while (true) {
      findFirstLetter(s, i);
      if (i == s.size()) break;
      for (; i < s.size(); i++) {
        if (s[i] != ' ') ss += s[i];
        else break;
      }
      ss += ' ';
    }

    string str = ss.substr(0, ss.size() - 1);
    reverse(str, 0, str.size() - 1);
    int j = 0, k = str.find(" ", j);
    while (k != -1) {
      reverse(str, j, k - 1);
      j = k + 1;
      k = str.find(" ", j);
    }
    reverse(str, j, str.size() - 1);
    return str;
  }
};

#endif //CPP_058_1__SOLUTION2_H_

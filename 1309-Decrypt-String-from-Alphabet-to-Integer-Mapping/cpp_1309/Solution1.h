//
// Created by ooooo on 2020/2/3.
//
#ifndef CPP_1309__SOLUTION1_H_
#define CPP_1309__SOLUTION1_H_

#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution {
 public:
  string freqAlphabets(string s) {
    unordered_map<string, char> m;
    for (int i = 1; i <= 26; ++i) {
      if (i < 10) {
        m[to_string(i)] = 'a' + i - 1;
      } else {
        m[to_string(i) + "#"] = 'a' + i - 1;
      }
    }
    stringstream ss;
    for (int i = 0; i < s.size();) {
      if (i + 2 < s.size() && s[i + 2] == '#') {
        ss << m[s.substr(i, 3)];
        i += 3;
      } else {
        ss << m[s.substr(i, 1)];
        i += 1;
      }
    }
    return ss.str();
  }
};

#endif //CPP_1309__SOLUTION1_H_

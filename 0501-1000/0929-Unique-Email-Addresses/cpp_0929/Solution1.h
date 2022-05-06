//
// Created by ooooo on 2020/2/1.
//
#ifndef CPP_0929__SOLUTION1_H_
#define CPP_0929__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
 public:
  int numUniqueEmails(vector<string> &emails) {
    unordered_set<string> set;
    stringstream ss;
    for (auto &s: emails) {
      int i = 0;
      bool hasPlus = false;
      for (; i < s.size(); ++i) {
        if (s[i] == '+') hasPlus = true;
        else if (s[i] == '@') break;
        else if (s[i] != '.' && !hasPlus) ss << s[i];
      }
      ss << s.substr(i, s.size() - i);
      set.insert(ss.str());
      ss.str("");
      // 清空状态，当ss.eof()
      ss.clear();
    }
    return set.size();
  }
};

#endif //CPP_0929__SOLUTION1_H_

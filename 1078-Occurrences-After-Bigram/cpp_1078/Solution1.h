//
// Created by ooooo on 2020/1/16.
//
#ifndef CPP_1078__SOLUTION1_H_
#define CPP_1078__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

  vector<string> split(string s) {
    vector<string> ans;
    int i = 0, j = s.find_first_of(" ", i);
    while (j != -1) {
      ans.push_back(s.substr(i, j - i));
      i = j + 1;
      j = s.find_first_of(" ", i);
    }
    ans.push_back(s.substr(i, s.size() - i));
    return ans;
  }

  vector<string> findOcurrences(string text, string first, string second) {
    vector<string> ans, words = split(text);
    for (int i = 0; i < words.size() - 2; ) {
      if (words[i] == first && words[i+1] == second) {
        ans.push_back(words[i + 2]);
        i += 2;
      }else {
        i++;
      }
    }

    return ans;
  }
};

#endif //CPP_1078__SOLUTION1_H_

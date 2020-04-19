//
// Created by ooooo on 2020/4/19.
//
#ifndef CPP_058_2__SOLUTION2_H_
#define CPP_058_2__SOLUTION2_H_

#include <iostream>

using namespace std;

class Solution {
 public:

  string reverseLeftWords(string s, int n) {
    string ans;
    reverse_copy(s.begin(), s.end(), back_inserter(ans));
    reverse(ans.begin(), ans.begin() + ans.size() - n);
    reverse(ans.begin() + ans.size() - n, ans.end());
    return ans;
  }
};

#endif //CPP_058_2__SOLUTION2_H_

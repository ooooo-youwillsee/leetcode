//
// Created by ooooo on 2020/1/26.
//
#ifndef CPP_0459__SOLUTION2_H_
#define CPP_0459__SOLUTION2_H_

#include <iostream>

using namespace std;

class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    /**
     * "abab"  ==> "abababab" ==> 2 != s.size()
     * "aba"   ==> "abaaba"  ==> 3 = s.size()
     */
    return (s + s).find(s, 1) != s.size();
  }
};

#endif //CPP_0459__SOLUTION2_H_

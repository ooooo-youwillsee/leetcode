//
// Created by ooooo on 2020/1/25.
//
#ifndef CPP_0067__SOLUTION1_H_
#define CPP_0067__SOLUTION1_H_

#include <iostream>

using namespace std;

/**
 * 从尾遍历到头
 */
class Solution {
 public:

  string addBinary(string a, string b) {
    string ans = "";
    int i = a.size() - 1, j = b.size() - 1;
    // flag表示是否需要进一
    bool flag = false;
    string aStr = "", bStr = "";
    while (i >= 0 || j >= 0) {
      aStr = i < 0 ? "0" : a.substr(i--, 1);
      bStr = j < 0 ? "0" : b.substr(j--, 1);
      if (flag) {
        if (aStr == "0" && bStr == "0") {
          flag = false;
          ans.insert(0, "1");
        } else if (aStr == "1" && bStr == "1") {
          ans.insert(0, "1");
        } else {
          ans.insert(0, "0");
        }
      } else {
        if (aStr == "0" && bStr == "0") {
          ans.insert(0, "0");
        } else if (aStr == "1" && bStr == "1") {
          flag = true;
          ans.insert(0, "0");
        } else {
          ans.insert(0, "1");
        }
      }
    }

    if (flag) {
      ans.insert(0, "1");
    }
    return ans;
  }
};

#endif //CPP_0067__SOLUTION1_H_

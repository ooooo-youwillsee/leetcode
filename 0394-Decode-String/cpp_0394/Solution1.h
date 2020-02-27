//
// Created by ooooo on 2020/2/27.
//
#ifndef CPP_0394__SOLUTION1_H_
#define CPP_0394__SOLUTION1_H_

#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

/**
 * stack
 */
class Solution {
 public:
  string decodeString(string s) {
    stack<char> stack;
    string ans = "", tmp = "";
    for (auto &c: s) {
      if (c != ']') {
        stack.push(c);
      } else {
        tmp = "";
        // 获取重复的字母
        while (!stack.empty() && stack.top() != '[') {
          tmp.push_back(stack.top());
          stack.pop();
        }
        stack.pop(); // 弹出'['
        string num = "", str = tmp;
        // 获取要重复的数字
        while (!stack.empty() && isdigit(stack.top())) {
          num.push_back(stack.top());
          stack.pop();
        }
        tmp = "";
        reverse(num.begin(), num.end());
        for (int i = 0, size = stoi(num); i < size; ++i) {
          tmp += str;
        }
        if (stack.empty()) {
          string ss;
          reverse_copy(tmp.begin(), tmp.end(), back_inserter(ss));
          ans += ss;
        } else {
          for (int i = tmp.size() - 1; i >= 0; --i) {
            stack.push(tmp[i]);
          }
        }

      }
    }
    tmp = "";
    while (!stack.empty()) {
      tmp.push_back(stack.top());
      stack.pop();
    }
    reverse(tmp.begin(), tmp.end());
    return ans + tmp;
  }
};

#endif //CPP_0394__SOLUTION1_H_

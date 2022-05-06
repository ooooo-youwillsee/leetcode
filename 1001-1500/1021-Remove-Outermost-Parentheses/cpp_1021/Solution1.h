//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_1021_SOLUTION1_H
#define CPP_1021_SOLUTION1_H

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> ss;
        string ans = "", mid = "";
        for (auto c: S) {
            mid += c;
            if (c == '(') ss.push(c);
            else {
                ss.pop();
                if (ss.empty()) {
                    ans += mid.substr(1, mid.size() - 2);
                    mid = "";
                }
            }
        }
        return ans;
    }
};

#endif //CPP_1021_SOLUTION1_H

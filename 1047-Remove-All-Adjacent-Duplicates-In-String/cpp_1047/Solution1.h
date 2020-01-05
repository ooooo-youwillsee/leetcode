//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_1047_SOLUTION1_H
#define CPP_1047_SOLUTION1_H

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> ss;
        for (auto c:S) {
            if (!ss.empty() && c == ss.top()) {
                ss.pop();
            } else {
                ss.push(c);
            }
        }

        string ans = "";
        while (!ss.empty()) {
            ans = ss.top() + ans;
            ss.pop();
        }
        return ans;
    }
};

#endif //CPP_1047_SOLUTION1_H

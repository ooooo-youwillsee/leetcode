//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0844_SOLUTION1_H
#define CPP_0844_SOLUTION1_H

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:

    stack<char> help(string s) {
        stack<char> ss;
        for (auto c: s) {
            if (c == '#') {
                if (!ss.empty()) {
                    ss.pop();
                }
                continue;
            }
            ss.push(c);
        }
        return ss;
    }

    bool backspaceCompare(string S, string T) {
        return help(S) == help(T);
    }
};

#endif //CPP_0844_SOLUTION1_H

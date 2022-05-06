//
// Created by ooooo on 2019/10/30.
//
#ifndef CPP_0020_SOLUTION1_H
#define CPP_0020_SOLUTION1_H

#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Solution1 {
public:
    bool isValid(string s) {
        stack<char> stack;
        map<char, char> map;
        map['}'] = '{';
        map[')'] = '(';
        map[']'] = '[';

        for (auto i : s) {
            if (map.find(i) == map.end()) {
                stack.push(i);
            } else {
                if (stack.empty() || stack.top() != map[i]) {
                    return false;
                } else {
                    stack.pop();
                }
            }
        }

        return stack.empty();
    }
};

#endif //CPP_0020_SOLUTION1_H

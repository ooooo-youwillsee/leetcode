//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0682_SOLUTION1_H
#define CPP_0682_SOLUTION1_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calPoints(vector<string> &ops) {
        stack<int> s;
        for (auto item: ops) {
            if (item == "+") {
                int first = s.top();
                s.pop();
                int second = s.top();
                s.push(first);
                s.push(first + second);
            } else if (item == "D") {
                s.push(s.top() * 2);
            } else if (item == "C") {
                s.pop();
            } else {
                s.push(stoi(item));
            }
        }

        int sum = 0;
        while (!s.empty()) {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};

#endif //CPP_0682_SOLUTION1_H

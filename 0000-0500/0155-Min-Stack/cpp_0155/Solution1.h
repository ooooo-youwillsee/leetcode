//
// Created by ooooo on 2019/12/30.
//
#ifndef CPP_0155_SOLUTION1_H
#define CPP_0155_SOLUTION1_H

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MinStack {

private:
    vector<int> data;
    int min = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
        data.clear();
    }

    void push(int x) {
        min = x < min ? x : min;
        data.push_back(x);
    }

    void pop() {
        int v = top();
        data.erase(end(data) - 1);
        if (v == min) {
            min = INT_MAX;
            for (auto num : data) {
                min = min < num ? min : num;
            }
        }
    }

    int top() {
        return data[data.size() - 1];
    }

    int getMin() {
        return min;
    }
};

#endif //CPP_0155_SOLUTION1_H

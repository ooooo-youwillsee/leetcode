//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0496_SOLUTION2_H
#define CPP_0496_SOLUTION2_H

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for (auto num: nums2) {
            while (!s.empty() && s.top() < num) {
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        vector<int> res;
        for (auto num: nums1) {
            if (m.count(num)) {
                res.push_back(m[num]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};

#endif //CPP_0496_SOLUTION2_H

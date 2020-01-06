//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0119_SOLUTION1_H
#define CPP_0119_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * 动态规划
 */
class Solution {
public:
    vector<int> getRow2(int rowIndex) {
        if (rowIndex == 0) return {1};
        vector<int> ans(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; ++i) {
            for (int rightIndex = i - 1; rightIndex > 0; --rightIndex) {
                ans[rightIndex] += ans[rightIndex - 1];
            }
        }
        return ans;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for (int i = 0; i <= rowIndex; ++i) {
            ans.push_back(1);
            for (int rightIndex = i - 1; rightIndex > 0; --rightIndex) {
                ans[rightIndex] += ans[rightIndex - 1];
            }
        }
        return ans;
    }
};

#endif //CPP_0119_SOLUTION1_H

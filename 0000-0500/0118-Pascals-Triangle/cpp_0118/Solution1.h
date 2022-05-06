//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0118_SOLUTION1_H
#define CPP_0118_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 1; i < numRows; ++i) {
            vector<int> prev = ans[i - 1];
            vector<int> next(prev.size() + 1, 1);
            for (int j = prev.size() - 1; j > 0; --j) {
                next[j] = prev[j] + prev[j - 1];
            }
            ans.push_back(next);
        }
        return ans;
    }
};

#endif //CPP_0118_SOLUTION1_H

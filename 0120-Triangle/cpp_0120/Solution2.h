//
// Created by ooooo on 2019/12/16.
//
#ifndef CPP_0120_SOLUTION2_H
#define CPP_0120_SOLUTION2_H

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 *  自底向上
 *
 *  res[i] = min (res[i] , res[j]) + res[row][i]
 */
class Solution {

public:
    int minimumTotal(vector<vector<int>> &triangle) {

        vector<int> res(triangle.size() + 1, 0);
        for (int i = triangle.size() - 1; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                res[j] = min(res[j], res[j + 1]) + triangle[i][j];
            }
        }
        return res[0];
    }
};

#endif //CPP_0120_SOLUTION2_H

//
// Created by ooooo on 2019/12/16.
//
#ifndef CPP_0120_SOLUTION1_H
#define CPP_0120_SOLUTION1_H

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * 可能会超出时间限制
 */
class Solution {

private:

    int min = INT_MAX;

    void dfs(vector<vector<int>> &vec, int row, int col, int sum) {
        if (col >= vec[row].size()) return;
        sum += vec[row][col];
        if (row == vec.size() - 1) {
            min = min < sum ? min : sum;
        } else {
            dfs(vec, row + 1, col, sum);
            dfs(vec, row + 1, col + 1, sum);
        }
    }

public:
    int minimumTotal(vector<vector<int>> &triangle) {
        dfs(triangle, 0, 0, 0);
        return min;
    }
};

#endif //CPP_0120_SOLUTION1_H

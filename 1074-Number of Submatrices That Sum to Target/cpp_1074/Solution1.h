//
// Created by ooooo on 5/31/2021.
//

#ifndef CPP_1074_SOLUTION1_H
#define CPP_1074_SOLUTION1_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + matrix[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                for (int p = i+1; p <= m; p++) {
                    for (int q = j+1; q <= n; q++) {
                        if (dp[p][q] - dp[p][j] - dp[i][q] + dp[i][j] == target) {
                            ans ++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

#endif //CPP_1074_SOLUTION1_H

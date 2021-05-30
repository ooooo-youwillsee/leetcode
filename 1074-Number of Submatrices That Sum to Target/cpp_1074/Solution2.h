//
// Created by ooooo on 5/31/2021.
//

#ifndef CPP_1074_SOLUTION2_H
#define CPP_1074_SOLUTION2_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int ans = 0;
        for (int p = 0; p < m; p++) {
            int cols[n];
            memset(cols, 0, sizeof(cols));
            for (int i = p; i < m; i++) {
                vector<int> preSum(n+1);
                unordered_map<int,int> m;
                m[0] = 1;
                for (int j = 0; j < n; j++) {
                    cols[j] += matrix[i][j];
                    preSum[j+1] = preSum[j] + cols[j];
                    if (m.find(preSum[j+1] - target) != m.end()) {
                        ans += m[preSum[j+1] - target];
                    }
                    m[preSum[j+1]]++;
                }
            }
        }
        return ans;
    }
};

#endif //CPP_1074_SOLUTION2_H

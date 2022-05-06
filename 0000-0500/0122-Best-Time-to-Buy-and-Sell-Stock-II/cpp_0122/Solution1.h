//
// Created by ooooo on 2019/11/4.
//
#ifndef CPP_0122_SOLUTION1_H
#define CPP_0122_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * 贪心算法
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 0; !prices.empty() && i < prices.size() - 1; ++i) {
            if (prices[i + 1] > prices[i]) {
                res += prices[i + 1] - prices[i];
            }
        }

        return res;
    }
};

#endif //CPP_0122_SOLUTION1_H

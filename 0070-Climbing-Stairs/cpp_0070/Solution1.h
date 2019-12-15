//
// Created by ooooo on 2019/12/15.
//
#ifndef CPP_0070_SOLUTION1_H
#define CPP_0070_SOLUTION1_H

/**
 * f(n) = f(n-1) + f(n-2)
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3)
            return n;
        int *res = new int[n + 1];
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i <= n; ++i) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n];
    }
};

#endif //CPP_0070_SOLUTION1_H

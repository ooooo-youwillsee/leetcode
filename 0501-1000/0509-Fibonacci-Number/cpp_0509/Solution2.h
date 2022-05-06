//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0509_SOLUTION2_H
#define CPP_0509_SOLUTION2_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * loop
 */
class Solution {
public:
    int fib2(int N) {
        if (N == 0 || N == 1) return N;
        vector<int> ans = {0, 1};
        for (int i = 2; i <= N; ++i) {
            ans.push_back(ans[i - 1] + ans[i - 2]);
        }
        return ans[N];
    }

    int fib(int N) {
        if (N == 0 || N == 1) return N;
        int a = 0, b = 1, ans = 0;
        for (int i = 2; i <= N; ++i) {
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};

#endif //CPP_0509_SOLUTION2_H

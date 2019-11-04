//
// Created by ooooo on 2019/11/4.
//
#ifndef CPP_0050_SOLUTION1_H
#define CPP_0050_SOLUTION1_H

class Solution {

private:
    double fastPow(double x, long long n) {
        if (n == 0) return 1.0;
        if (n & 1) return x * fastPow(x, n - 1);
        return fastPow(x * x, n / 2);
    }

public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
};

#endif //CPP_0050_SOLUTION1_H

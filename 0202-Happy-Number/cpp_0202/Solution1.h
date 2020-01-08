//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0202_SOLUTION1_H
#define CPP_0202_SOLUTION1_H

#include <iostream>
#include <cmath>

using namespace std;

/**
 * 设定一个限制
 *
 */
class Solution {
public:

    int help(int num) {
        int sum = 0;
        while (num) {
            sum += pow(num % 10, 2);
            num /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        if (n == 1) return true;
        for (int i = 0; i < 1000; ++i) {
            n = help(n);
            if (n == 1)return true;
        }
        return false;
    }
};

#endif //CPP_0202_SOLUTION1_H

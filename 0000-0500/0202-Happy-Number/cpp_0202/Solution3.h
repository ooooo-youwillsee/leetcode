//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0202_SOLUTION3_H
#define CPP_0202_SOLUTION3_H


#include <iostream>
#include <cmath>

using namespace std;

/**
 *
 * 快慢指针
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
        int low = n, fast = n;
        while (true) {
            // 慢指针
            low = help(low);
            // 快指针
            fast = help(help(fast));
            if (low == 1) return true;
            if (low == fast) return false;
        }
    }
};


#endif //CPP_0202_SOLUTION3_H

//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0202_SOLUTION2_H
#define CPP_0202_SOLUTION2_H


#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

/**
 *
 * 哈希表 (先insert，计算之后如果还存在， 就是false)
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
        unordered_set<int> s;
        while (true) {
            if (n == 1) return true;
            s.insert(n);
            n = help(n);
            if (s.count(n)) return false;
        }
    }
};

#endif //CPP_0202_SOLUTION2_H

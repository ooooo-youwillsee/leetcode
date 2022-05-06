//
// Created by ooooo on 2020/1/8.
//
#ifndef CPP_0204_SOLUTION1_H
#define CPP_0204_SOLUTION1_H


#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:

    bool isPrime(int num) {
        if (num == 2) return true;
        if ((num & 1) == 0 || num == 1) {
            return false;
        }
        int max = int(sqrt(num) + 1);
        for (int i = 3; i <= max; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        int ans = 0;
        for (int i = n - 1; i >= 2; i--) {
            if (isPrime(i)) {
                ans++;
            }
        }
        return ans;
    }
};

#endif //CPP_0204_SOLUTION1_H

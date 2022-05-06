//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0509_SOLUTION1_H
#define CPP_0509_SOLUTION1_H

#include <iostream>

using namespace std;

/**
 * recursion
 */
class Solution {
public:
    int fib(int N) {
        if (N == 0 || N == 1) return N;
        return fib(N - 1) + fib(N - 2);
    }
};

#endif //CPP_0509_SOLUTION1_H

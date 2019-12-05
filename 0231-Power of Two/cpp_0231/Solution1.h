//
// Created by ooooo on 2019/12/5.
//
#ifndef CPP_0231_SOLUTION1_H
#define CPP_0231_SOLUTION1_H

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & n - 1) == 0;
    }
};

#endif //CPP_0231_SOLUTION1_H

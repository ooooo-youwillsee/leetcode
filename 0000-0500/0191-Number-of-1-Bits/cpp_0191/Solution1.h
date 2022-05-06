//
// Created by ooooo on 2019/12/5.
//
#ifndef CPP_0191_SOLUTION1_H
#define CPP_0191_SOLUTION1_H

#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res +=1;
            n &= n-1;
        }
        return res;
    }
};

#endif //CPP_0191_SOLUTION1_H

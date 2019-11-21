//
// Created by ooooo on 2019/11/21.
//
#ifndef CPP_0069_SOLUTION1_H
#define CPP_0069_SOLUTION1_H

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 ) return 0;
        for (int i = 1; i <= x; ++i) {
            if (i == x / i) return i;
            if (i > x / i) return i - 1;
        }
        return -1;
    }
};

#endif //CPP_0069_SOLUTION1_H

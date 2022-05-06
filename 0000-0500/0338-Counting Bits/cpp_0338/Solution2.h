//
// Created by ooooo on 2019/12/5.
//
#ifndef CPP_0338_SOLUTION2_H
#define CPP_0338_SOLUTION2_H


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res = vector<int>(num + 1, 0);

        for (int i = 1; i <= num; i++) {
            res[i] = res[i & i - 1] + 1;
        }

        return res;
    }
};

#endif //CPP_0338_SOLUTION2_H

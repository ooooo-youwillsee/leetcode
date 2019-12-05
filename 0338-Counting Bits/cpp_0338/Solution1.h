//
// Created by ooooo on 2019/12/5.
//
#ifndef CPP_0338_SOLUTION1_H
#define CPP_0338_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res = vector<int>(num + 1, 0);

        for (int i = 1; i <= num; i++) {
            int n = i;
            int count = 0;
            while (n) {
                count++;
                n &= n - 1;
            }
            res[i] = count;
        }

        return res;
    }
};

#endif //CPP_0338_SOLUTION1_H

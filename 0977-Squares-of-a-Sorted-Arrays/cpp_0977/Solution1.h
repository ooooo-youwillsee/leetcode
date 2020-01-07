//
// Created by ooooo on 2020/1/7.
//
#ifndef CPP_0977_SOLUTION1_H
#define CPP_0977_SOLUTION1_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * sort
 */
class Solution {
public:

    vector<int> sortedSquares(vector<int> &A) {
        for (int i = 0; i < A.size(); ++i) {
            A[i] = pow(A[i], 2);
        }
        sort(A.begin(), A.end());
        return A;
    }
};

#endif //CPP_0977_SOLUTION1_H

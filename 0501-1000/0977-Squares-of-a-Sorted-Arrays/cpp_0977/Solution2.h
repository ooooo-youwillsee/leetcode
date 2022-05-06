//
// Created by ooooo on 2020/1/7.
//
#ifndef CPP_0977_SOLUTION2_H
#define CPP_0977_SOLUTION2_H


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 双指针
 */
class Solution {
public:

    vector<int> sortedSquares(vector<int> &A) {
        if (A.empty()) return A;
        int i = 0; // 第一个正数index
        while (i <= A.size() - 1 && A[i] < 0) i++;
        int j = i - 1; // 第一个负数index

        vector<int> ans;
        while (i < A.size() || j >= 0) {
            if (i == A.size()) {
                ans.push_back(A[j] * A[j]);
                j--;
                continue;
            }
            if (j == -1) {
                ans.push_back(A[i] * A[i]);
                i++;
                continue;
            }
            int a = A[i] * A[i];
            int b = A[j] * A[j];
            if (a > b) {
                ans.push_back(b);
                j--;
            } else {
                ans.push_back(a);
                i++;
            }
        }

        return ans;
    }
};

#endif //CPP_0977_SOLUTION2_H

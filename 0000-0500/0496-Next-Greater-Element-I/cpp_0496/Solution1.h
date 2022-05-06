//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0496_SOLUTION1_H
#define CPP_0496_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * 暴力破解
 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        for (auto num1: nums1) {
            int find = -1;
            for (int i = 0; i < nums2.size(); ++i) {
                if (nums2[i] == num1) {
                    // 向nums1的后面找
                    for (int j = i + 1; j < nums2.size(); ++j) {
                        if (nums2[j] > num1) {
                            find = nums2[j];
                            break;
                        }
                    }
                    break;
                }
            }
            res.push_back(find);
        }
        return res;
    }
};

#endif //CPP_0496_SOLUTION1_H

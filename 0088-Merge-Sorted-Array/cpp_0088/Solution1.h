//
// Created by ooooo on 2019/12/5.
//
#ifndef CPP_0088_SOLUTION1_H
#define CPP_0088_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        if (nums1.empty() && nums2.empty()) return;

        vector<int> target(m + n);
        for (int i = 0, j = 0, k = 0; i < m || j < n; k++) {
            if (i == m) {
                target[k] = nums2[j];
                j++;
                continue;
            }

            if (j == n) {
                target[k] = nums1[i];
                i++;
                continue;
            }

            if (nums1[i] <= nums2[j]) {
                target[k] = nums1[i];
                i++;
            } else {
                target[k] = nums2[j];
                j++;
            }
        }
        for (int l = 0; l < m + n; ++l) {
            nums1[l] = target[l];
        }
    }
};

#endif //CPP_0088_SOLUTION1_H

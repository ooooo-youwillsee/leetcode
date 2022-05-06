//
// Created by ooooo on 2019/12/5.
//
#ifndef CPP_0088_SOLUTION2_H
#define CPP_0088_SOLUTION2_H

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> vec(nums1.begin(), nums1.begin() + m);

        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
            nums1[k++] = vec[i] <= nums2[j] ? vec[i++] : nums2[j++];

        while (i < m)
            nums1[k++] = vec[i++];

        while (j < n)
            nums1[k++] = nums2[j++];
    }
};

#endif //CPP_0088_SOLUTION2_H

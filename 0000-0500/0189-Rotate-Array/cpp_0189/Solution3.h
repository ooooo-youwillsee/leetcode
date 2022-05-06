//
// Created by ooooo on 2019/12/5.
//
#ifndef CPP_0189_SOLUTION3_H
#define CPP_0189_SOLUTION3_H


#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
    void reverse(vector<int> &nums, int start, int end) {
        if (nums.size() == 0) return;
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

public:
    void rotate(vector<int> &nums, int k) {
        if (nums.size() == 0) return;
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

};


#endif //CPP_0189_SOLUTION3_H

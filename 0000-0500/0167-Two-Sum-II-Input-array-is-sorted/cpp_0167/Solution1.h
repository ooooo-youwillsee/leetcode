//
// Created by ooooo on 2020/1/6.
//
#ifndef CPP_0167_SOLUTION1_H
#define CPP_0167_SOLUTION1_H

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int i = 0, j = numbers.size() - 1; i < j;) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) return {i + 1, j + 1};
            else if (sum < target) i++;
            else j--;
        }
        return {};
    }
};

#endif //CPP_0167_SOLUTION1_H

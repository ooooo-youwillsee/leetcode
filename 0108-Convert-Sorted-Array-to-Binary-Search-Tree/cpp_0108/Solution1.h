//
// Created by ooooo on 2020/1/2.
//
#ifndef CPP_0108_SOLUTION1_H
#define CPP_0108_SOLUTION1_H

#include "TreeNode.h"
#include <vector>

class Solution {

public:

    // 复制vector，时空复杂度变低
    TreeNode *sortedArrayToBST2(vector<int> &nums) {
        if (nums.empty()) return nullptr;
        // 节点向左偏
        int mid = nums.size() / 2;
        // 节点向右偏
        //int mid = (nums.size() - 1) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        node->left = sortedArrayToBST(left);
        node->right = sortedArrayToBST(right);
        return node;
    }


    TreeNode *help(vector<int> &nums, int left, int right) {
        if (left == right || nums.empty()) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = help(nums, left, mid);
        node->right = help(nums, mid + 1, right);
        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return help(nums, 0, nums.size());
    }
};

#endif //CPP_0108_SOLUTION1_H

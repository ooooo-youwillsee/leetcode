//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_1022_SOLUTION1_H
#define CPP_1022_SOLUTION1_H

#include "TreeNode.h"
#include <vector>

class Solution {
public:

    vector<string> nums;

    void dfs(TreeNode *node, string s) {
        if (!node) return;
        s += to_string(node->val);
        if (!node->left && !node->right) {
            nums.push_back(s);
            return;
        }
        dfs(node->left, s);
        dfs(node->right, s);
    }

    int sumRootToLeaf(TreeNode *root) {
        dfs(root, "");
        int sum = 0;
        for (auto num: nums) {
            sum += stoi(num, 0, 2);
        }
        return sum;
    }
};

#endif //CPP_1022_SOLUTION1_H

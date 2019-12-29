//
// Created by ooooo on 2019/12/29.
//
#ifndef CPP_0112_SOLUTION1_H
#define CPP_0112_SOLUTION1_H

#include "TreeNode.h"

class Solution {

private:

    bool dfs(TreeNode *node, int currentSum, int sum) {
        if (!node) return false;
        currentSum += node->val;
        if (!node->left && !node->right && currentSum == sum) {
            return true;
        }
        return dfs(node->left, currentSum, sum) || dfs(node->right, currentSum, sum);
    }

public:

    bool hasPathSum(TreeNode *root, int sum) {
        return dfs(root, 0, sum);
    }
};

#endif //CPP_0112_SOLUTION1_H

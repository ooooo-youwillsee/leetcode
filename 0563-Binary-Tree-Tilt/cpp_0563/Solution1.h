//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0563_SOLUTION1_H
#define CPP_0563_SOLUTION1_H

#include "TreeNode.h"

class Solution {
public:

    int res = 0;

    int dfs(TreeNode *node) {
        if (!node) return 0;
        int leftSum = dfs(node->left);
        int rightSum = dfs(node->right);
        res += abs(leftSum - rightSum);
        return leftSum + rightSum + node->val;
    }

    int findTilt(TreeNode *root) {
        dfs(root);
        return res;
    }
};

#endif //CPP_0563_SOLUTION1_H

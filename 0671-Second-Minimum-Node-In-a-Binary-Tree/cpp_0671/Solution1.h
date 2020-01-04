//
// Created by ooooo on 2020/1/4.
//
#ifndef CPP_0671_SOLUTION1_H
#define CPP_0671_SOLUTION1_H

#include "TreeNode.h"

class Solution {
public:


    int dfs(TreeNode *node, int min) {
        if (!node) return -1;
        if (node->val > min) return node->val;
        int left = dfs(node->left, min);
        int right = dfs(node->right, min);
        if (left == -1) return right;
        if (right == -1) return left;
        return std::min(left, right);
    }

    int findSecondMinimumValue(TreeNode *root) {
        if (!root) return -1;
        return dfs(root, root->val);
    }
};

#endif //CPP_0671_SOLUTION1_H

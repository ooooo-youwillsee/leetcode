//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0783_SOLUTION2_H
#define CPP_0783_SOLUTION2_H

#include "TreeNode.h"
#include <climits>

class Solution {
public:

    TreeNode *prev = nullptr;
    int min = INT_MAX;

    void dfs(TreeNode *node) {
        if (!node) return;
        dfs(node->left);
        if (prev) {
            min = std::min(min, node->val - prev->val);
        }
        prev = node;
        dfs(node->right);
    }

    int minDiffInBST(TreeNode *root) {
        if (!root) return 0;
        dfs(root);
        return min;
    }
};

#endif //CPP_0783_SOLUTION2_H

//
// Created by ooooo on 2019/11/4.
//
#ifndef CPP_0111_SOLUTION1_H
#define CPP_0111_SOLUTION1_H

#include "TreeNode.h"

class Solution {

private:
    int min = 0;

    void dfs(int level, TreeNode *node) {
        if (!node) return;

        if (!node->left && !node->right) {
            if (min == 0) {
                // min为0，表明第一次
                min = level;
            } else if (level < min) {
                min = level;
            }
        }
        dfs(level + 1, node->left);
        dfs(level + 1, node->right);
    }

public:
    int minDepth(TreeNode *root) {
        dfs(1, root);
        return this->min;
    }
};

#endif //CPP_0111_SOLUTION1_H

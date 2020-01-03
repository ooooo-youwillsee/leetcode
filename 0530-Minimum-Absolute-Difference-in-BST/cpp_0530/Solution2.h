//
// Created by ooooo on 2020/1/2.
//
#ifndef CPP_0530_SOLUTION2_H
#define CPP_0530_SOLUTION2_H

#include "TreeNode.h"
#include <climits>

/**
 * 中序遍历， prev 存储前一个节点
 */
class Solution {
public:

    int min;
    TreeNode *prev;

    void inOrder(TreeNode *node) {
        if (!node) return;

        inOrder(node->left);
        if (prev != nullptr) {
            min = std::min(min, node->val - prev->val);
        }
        prev = node;
        inOrder(node->right);
    }

    int getMinimumDifference(TreeNode *root) {
        if (!root) return 0;
        min = INT_MAX;
        prev = nullptr;
        inOrder(root);
        return min;
    }
};

#endif //CPP_0530_SOLUTION2_H

//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0897_SOLUTION1_H
#define CPP_0897_SOLUTION1_H

#include "TreeNode.h"

class Solution {
public:

    TreeNode *prev = nullptr;

    void inOrder(TreeNode *node) {
        if (!node) return;
        inOrder(node->left);
        prev->right = node;
        node->left = nullptr;
        prev = node;
        inOrder(node->right);
    }

    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *ans = new TreeNode(0);
        prev = ans;
        inOrder(root);
        return ans->right;
    }
};

#endif //CPP_0897_SOLUTION1_H

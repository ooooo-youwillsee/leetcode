//
// Created by ooooo on 2020/1/2.
//
#ifndef CPP_0226_SOLUTION1_H
#define CPP_0226_SOLUTION1_H

#include "TreeNode.h"

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return nullptr;
        TreeNode *rightNode = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(rightNode);
        return root;
    }
};

#endif //CPP_0226_SOLUTION1_H

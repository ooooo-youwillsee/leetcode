//
// Created by ooooo on 2019/12/31.
//
#ifndef CPP_0965_SOLUTION1_H
#define CPP_0965_SOLUTION1_H

#include "TreeNode.h"

class Solution {

public:

    bool dfs(TreeNode *node, int x) {
        if (!node) return true;
        return node->val == x && dfs(node->left, x) && dfs(node->right, x);
    }

    bool isUnivalTree(TreeNode *root) {
        if (!root) return true;
        return dfs(root, root->val);
    }
};

#endif //CPP_0965_SOLUTION1_H

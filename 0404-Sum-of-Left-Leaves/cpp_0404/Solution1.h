//
// Created by ooooo on 2020/1/2.
//
#ifndef CPP_0404_SOLUTION1_H
#define CPP_0404_SOLUTION1_H

#include "TreeNode.h"

class Solution {
public:

    int help(TreeNode *node, bool isLeft) {
        if (!node) return 0;
        int x = isLeft && !node->left && !node->right ? node->val : 0;
        return help(node->left, true) + help(node->right, false) + x;
    }

    int sumOfLeftLeaves(TreeNode *root) {
        return help(root, false);
    }
};

#endif //CPP_0404_SOLUTION1_H

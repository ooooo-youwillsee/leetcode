//
// Created by ooooo on 2019/12/28.
//
#ifndef CPP_0110_SOLUTION1_H
#define CPP_0110_SOLUTION1_H

#include "TreeNode.h"

class Solution {

private:

    int depth(TreeNode *node) {
        if (!node) return 0;
        return max(depth(node->left), depth(node->right)) + 1;
    }

public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 &&
               isBalanced(root->left) && isBalanced(root->right);
    }
};

#endif //CPP_0110_SOLUTION1_H

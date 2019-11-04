//
// Created by ooooo on 2019/11/4.
//
#ifndef CPP_0111_SOLUTION2_H
#define CPP_0111_SOLUTION2_H

#include "TreeNode.h"

class Solution {

public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

#endif //CPP_0111_SOLUTION2_H

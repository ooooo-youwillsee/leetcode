//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0700_SOLUTION1_H
#define CPP_0700_SOLUTION1_H

#include "TreeNode.h"

class Solution {
public:

    TreeNode *searchBST(TreeNode *root, int val) {
        if (!root) return nullptr;
        if (root->val < val) {
            return searchBST(root->right, val);
        } else if (root->val > val) {
            return searchBST(root->left, val);
        }
        return root;
    }
};

#endif //CPP_0700_SOLUTION1_H

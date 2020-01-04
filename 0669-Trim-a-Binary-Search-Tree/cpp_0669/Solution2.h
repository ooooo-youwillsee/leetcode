//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0669_SOLUTION2_H
#define CPP_0669_SOLUTION2_H

#include "TreeNode.h"


class Solution {
public:
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (!root) return nullptr;

        if (root->val > R) return trimBST(root->left, L, R);
        if (root->val < L) return trimBST(root->right, L, R);
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

#endif //CPP_0669_SOLUTION2_H

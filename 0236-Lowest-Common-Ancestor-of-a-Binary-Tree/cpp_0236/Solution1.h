//
// Created by ooooo on 2019/11/3.
//
#ifndef CPP_0236_SOLUTION1_H
#define CPP_0236_SOLUTION1_H

#include "TreeNode.h"

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return NULL;
        if (root == p || root == q) return root;
        TreeNode *res1 = lowestCommonAncestor(root->left, p, q);
        TreeNode *res2 = lowestCommonAncestor(root->right, p, q);
        if (res1) {
            if (res2) return root;
            return res1;
        }
        if (res2) return res2;
        return NULL;
    }
};

#endif //CPP_0236_SOLUTION1_H

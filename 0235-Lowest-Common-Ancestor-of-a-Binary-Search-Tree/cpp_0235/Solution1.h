//
// Created by ooooo on 2019/11/3.
//
#ifndef CPP_0235_SOLUTION1_H
#define CPP_0235_SOLUTION1_H

#include "TreeNode.h"
#include <queue>

class Solution {

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root) return NULL;

        if (root == p || root == q) return root;

        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};

#endif //CPP_0235_SOLUTION1_H

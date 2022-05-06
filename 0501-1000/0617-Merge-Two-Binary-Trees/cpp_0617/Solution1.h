//
// Created by ooooo on 2019/12/31.
//
#ifndef CPP_0617_SOLUTION1_H
#define CPP_0617_SOLUTION1_H

#include "TreeNode.h"

class Solution {

public:

    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) return nullptr;
        if (!t1) return t2;
        if (!t2) return t1;

        // 重用旧节点
        t1->val = t1->val + t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

#endif //CPP_0617_SOLUTION1_H

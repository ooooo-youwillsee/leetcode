//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0572_SOLUTION1_H
#define CPP_0572_SOLUTION1_H

#include "TreeNode.h"

class Solution {
public:

    bool isSameTree(TreeNode *s, TreeNode *t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }

    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (!s) return false;
        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};

#endif //CPP_0572_SOLUTION1_H

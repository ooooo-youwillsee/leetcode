//
// Created by ooooo on 2019/12/6.
//
#ifndef CPP_0100_SOLUTION1_H
#define CPP_0100_SOLUTION1_H

#include "TreeNode.h"

class Solution {

private:

    bool dfs(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q) {
            return false;
        }
        return p->val == q->val && dfs(p->left, q->left) && dfs(p->right, q->right);
    }


public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        return dfs(p, q);
    }
};

#endif //CPP_0100_SOLUTION1_H

//
// Created by ooooo on 2019/12/6.
//
#ifndef CPP_0101_SOLUTION1_H
#define CPP_0101_SOLUTION1_H

#include "TreeNode.h"
#include <vector>

class Solution {

private:

    bool dfs(TreeNode *node1, TreeNode *node2) {
        if (!node1 && !node2) return true;
        if (!node1 || !node2) return false;
        return node1->val == node2->val && dfs(node1->left, node2->right) && dfs(node1->right, node2->left);
    }

public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return dfs(root->left, root->right);
    }
};

#endif //CPP_0101_SOLUTION1_H

//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0993_SOLUTION2_H
#define CPP_0993_SOLUTION2_H

#include "TreeNode.h"

class Solution {
public:

    int xDepth = 0, yDepth = 0;
    TreeNode *xParent = nullptr, *yParent = nullptr;
    int x, y;

    void dfs(TreeNode *node, int depth, TreeNode *parent) {
        if (!node) return;
        if (node->val == x) {
            xParent = parent;
            xDepth = depth;
        }
        if (node->val == y) {
            yParent = parent;
            yDepth = depth;
        }
        depth += 1;
        dfs(node->left, depth, node);
        dfs(node->right, depth, node);
    }

    bool isCousins(TreeNode *root, int x, int y) {
        if (!root) return false;
        this->x = x;
        this->y = y;
        dfs(root, 0, nullptr);
        return xDepth == yDepth && xParent != yParent;
    }
};

#endif //CPP_0993_SOLUTION2_H

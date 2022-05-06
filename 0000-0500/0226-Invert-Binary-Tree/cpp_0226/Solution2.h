//
// Created by ooooo on 2020/1/2.
//
#ifndef CPP_0226_SOLUTION2_H
#define CPP_0226_SOLUTION2_H

#include <queue>
#include "TreeNode.h"

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return nullptr;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            TreeNode *rightNode = node->right;
            node->right = node->left;
            node->left = rightNode;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};


#endif //CPP_0226_SOLUTION2_H

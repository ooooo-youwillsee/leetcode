//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0993_SOLUTION1_H
#define CPP_0993_SOLUTION1_H

#include "TreeNode.h"
#include <queue>

/**
 * bfs
 */
class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        if (!root) return false;
        queue<TreeNode *> q;
        queue<TreeNode *> parents;
        q.push(root);
        parents.push(root);
        while (!q.empty()) {
            int size = q.size();
            bool findX = false, findY = false;
            TreeNode *xParent = nullptr, *yParent = nullptr;
            while (size--) {
                TreeNode *node = q.front();
                q.pop();
                TreeNode *parent = parents.front();
                parents.pop();
                if (node->val == x) {
                    findX = true;
                    xParent = parent;
                }
                if (node->val == y) {
                    findY = true;
                    yParent = parent;
                }
                if (node->left) {
                    q.push(node->left);
                    parents.push(node);
                }
                if (node->right) {
                    q.push(node->right);
                    parents.push(node);
                }
            }
            if (findX != findY) return false;
            if (findX) return xParent != yParent;
        }
        return false;
    }
};

#endif //CPP_0993_SOLUTION1_H

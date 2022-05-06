//
// Created by ooooo on 2019/12/31.
//
#ifndef CPP_0965_SOLUTION2_H
#define CPP_0965_SOLUTION2_H

#include "TreeNode.h"
#include <queue>

class Solution {

public:

    bool isUnivalTree(TreeNode *root) {
        if (!root) return true;
        int x = root->val;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode *node = q.front();
                q.pop();
                if (node->val != x) {
                    return false;
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return true;
    }
};

#endif //CPP_0965_SOLUTION2_H

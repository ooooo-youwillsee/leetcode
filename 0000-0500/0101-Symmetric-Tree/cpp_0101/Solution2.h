//
// Created by ooooo on 2019/12/6.
//
#ifndef CPP_0101_SOLUTION2_H
#define CPP_0101_SOLUTION2_H

#include "TreeNode.h"
#include <queue>

class Solution {

public:
    bool isSymmetric(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);

        while (!q.empty()) {
            TreeNode *node1 = q.front();
            q.pop();
            TreeNode *node2 = q.front();
            q.pop();

            if (!node1 && !node2) continue;
            if (!node1 || !node2) return false;
            if (node1->val != node2->val) return false;
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }

};

#endif //CPP_0101_SOLUTION2_H

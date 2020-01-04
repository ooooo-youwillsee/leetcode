//
// Created by ooooo on 2020/1/4.
//
#ifndef CPP_0671_SOLUTION2_H
#define CPP_0671_SOLUTION2_H

#include "TreeNode.h"
#include <queue>

class Solution {
public:
    int findSecondMinimumValue(TreeNode *root) {
        if (!root) return -1;
        queue<TreeNode *> q;
        q.push(root);
        // flag 定义最小值是否有INT_MAX
        int res = INT_MAX, flag = 0;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->val > root->val) {
                res = std::min(res, node->val);
                flag = node->val == INT_MAX ? 1 : flag;
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return res == INT_MAX && !flag ? -1 : res;
    }
};

#endif //CPP_0671_SOLUTION2_H

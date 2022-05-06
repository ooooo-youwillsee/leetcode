//
// Created by ooooo on 2019/12/29.
//
#ifndef CPP_0103_SOLUTION1_H
#define CPP_0103_SOLUTION1_H

#include "TreeNode.h"
#include <vector>
#include <queue>

class Solution {

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return {};
        queue<TreeNode *> q;
        q.push(root);

        vector<vector<int>> res;
        bool reverse = false;
        while (!q.empty()) {
            vector<int> vec;
            for (int i = 0, len = q.size(); i < len; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (reverse) {
                    vec.insert(begin(vec), node->val);
                } else {
                    vec.push_back(node->val);
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            reverse = !reverse;
            res.push_back(vec);
        }
        return res;
    }
};

#endif //CPP_0103_SOLUTION1_H

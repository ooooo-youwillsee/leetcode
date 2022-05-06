//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0637_SOLUTION1_H
#define CPP_0637_SOLUTION1_H

#include "TreeNode.h"
#include <queue>
#include <vector>

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        if (!root) return {};
        vector<double> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size(), count = q.size();
            double sum = 0;
            while (size--) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(sum / count);
        }
        return res;
    }

};

#endif //CPP_0637_SOLUTION1_H

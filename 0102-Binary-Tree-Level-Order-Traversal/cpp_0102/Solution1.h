//
// Created by ooooo on 2019/11/4.
//
#ifndef CPP_0102_SOLUTION1_H
#define CPP_0102_SOLUTION1_H

#include <iostream>
#include "TreeNode.h"
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;

            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                vec.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }

            res.push_back(vec);
        }

        return res;
    }
};

#endif //CPP_0102_SOLUTION1_H

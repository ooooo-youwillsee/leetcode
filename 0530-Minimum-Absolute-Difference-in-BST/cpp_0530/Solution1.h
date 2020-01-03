//
// Created by ooooo on 2020/1/2.
//
#ifndef CPP_0530_SOLUTION1_H
#define CPP_0530_SOLUTION1_H

#include "TreeNode.h"
#include <vector>
#include <climits>


class Solution {
public:

    void dfs(TreeNode *node, vector<int> &vec) {
        if (!node) return;

        dfs(node->left, vec);
        vec.push_back(node->val);
        dfs(node->right, vec);
    }

    int getMinimumDifference(TreeNode *root) {
        vector<int> vec;
        dfs(root, vec);
        int min = INT_MAX;
        for (int i = vec.size() - 1; i > 0; --i) {
            int diff = vec[i] - vec[i - 1];
            min = diff < min ? diff : min;
        }
        return min == INT_MAX ? 0 : min;
    }
};

#endif //CPP_0530_SOLUTION1_H

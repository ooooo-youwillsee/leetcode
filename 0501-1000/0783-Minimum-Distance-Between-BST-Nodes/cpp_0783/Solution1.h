//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0783_SOLUTION1_H
#define CPP_0783_SOLUTION1_H

#include "TreeNode.h"
#include <vector>

class Solution {
public:

    void dfs(TreeNode *node, vector<int> &vec) {
        if (!node) return;
        dfs(node->left, vec);
        vec.push_back(node->val);
        dfs(node->right, vec);
    }

    int minDiffInBST(TreeNode *root) {
        if (!root) return 0;
        vector<int> vec;
        dfs(root, vec);
        int min = INT_MAX;
        for (int i = 0; i < vec.size() - 1; ++i) {
            min = std::min(min, vec[i + 1] - vec[i]);
        }
        return min;
    }
};

#endif //CPP_0783_SOLUTION1_H

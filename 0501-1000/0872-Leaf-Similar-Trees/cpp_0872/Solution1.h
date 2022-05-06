//
// Created by ooooo on 2020/1/5.
//
#ifndef CPP_0872_SOLUTION1_H
#define CPP_0872_SOLUTION1_H

#include "TreeNode.h"
#include <vector>

class Solution {
public:

    void dfs(TreeNode *node, vector<int> &vec) {
        if (!node) return;
        dfs(node->left, vec);
        if (!node->left && !node->right) {
            vec.push_back(node->val);
        }
        dfs(node->right, vec);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) return true;
        vector<int> vec1, vec2;
        dfs(root1, vec1);
        dfs(root2, vec2);
        return vec1 == vec2;
    }
};

#endif //CPP_0872_SOLUTION1_H

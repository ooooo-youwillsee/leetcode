//
// Created by ooooo on 2019/11/4.
//
#ifndef CPP_0102_SOLUTION2_H
#define CPP_0102_SOLUTION2_H


#include <iostream>
#include "TreeNode.h"
#include <queue>
#include <vector>

using namespace std;

class Solution {

private:

    vector<vector<int>> res;

    void dfs(int level, TreeNode *node) {
        if (!node) return;

        if (res.size() < level) res.push_back({});

        res[level - 1].push_back(node->val);
        dfs(level + 1, node->left);
        dfs(level + 1, node->right);
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) {
            return res;
        }
        dfs(1, root);

        return res;
    }
};

#endif //CPP_0102_SOLUTION2_H

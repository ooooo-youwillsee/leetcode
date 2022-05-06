//
// Created by ooooo on 2019/11/4.
//
#ifndef CPP_0104_SOLUTION1_H
#define CPP_0104_SOLUTION1_H

#include "TreeNode.h"

using namespace std;

class Solution {

private:

    int max = 0;

    void dfs(int level, TreeNode *node) {
        if (!node) return;

        if (level > max) max = level;
        dfs(level + 1, node->left);
        dfs(level + 1, node->right);
    }

public:
    int maxDepth(TreeNode *root) {
        dfs(1, root);
        return this->max;
    }
};

#endif //CPP_0104_SOLUTION1_H

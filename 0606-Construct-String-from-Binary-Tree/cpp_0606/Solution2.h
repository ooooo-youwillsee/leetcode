//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0606_SOLUTION2_H
#define CPP_0606_SOLUTION2_H

#include "TreeNode.h"

/**
 * 无返回值快。 前序遍历
 */
class Solution {
public:

    void dfs(TreeNode *node, string &s) {
        if (!node) return;
        s += to_string(node->val);
        if (node->left || node->right) {
            s += "(";
            dfs(node->left, s);
            s += ")";
        }
        if (node->right) {
            s += "(";
            dfs(node->right, s);
            s += ")";
        }
    }

    string tree2str(TreeNode *t) {
        string s = "";
        dfs(t, s);
        return s;
    }
};

#endif //CPP_0606_SOLUTION2_H

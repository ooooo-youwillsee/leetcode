//
// Created by ooooo on 2020/1/2.
//
#ifndef CPP_0257_SOLUTION2_H
#define CPP_0257_SOLUTION2_H

#include "TreeNode.h"
#include <vector>


class Solution {

public:

    void help(TreeNode *node, string s, vector<string> &res) {
        if (s == "") {
            s = to_string(node->val);
        } else {
            s += "->" + to_string(node->val);
        }
        if (!node->left && !node->right) {
            res.push_back(s);
            return;
        }

        if (node->left)
            help(node->left, s, res);
        if (node->right)
            help(node->right, s, res);
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root) return {};
        vector<string> res;
        help(root, "", res);
        return res;
    }
};

#endif //CPP_0257_SOLUTION2_H

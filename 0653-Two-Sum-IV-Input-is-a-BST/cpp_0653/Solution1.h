//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0653_SOLUTION1_H
#define CPP_0653_SOLUTION1_H

#include "TreeNode.h"
#include <unordered_set>

class Solution {
public:


    bool dfs(TreeNode *node, unordered_set<int> &s, int k) {
        if (!node) return false;
        if (s.count(k - node->val)) return true;
        s.insert(node->val);
        return dfs(node->left, s, k) || dfs(node->right, s, k);
    }


    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> s;
        return dfs(root, s, k);
    }
};

#endif //CPP_0653_SOLUTION1_H

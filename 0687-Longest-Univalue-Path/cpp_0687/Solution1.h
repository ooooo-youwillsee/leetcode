//
// Created by ooooo on 2020/1/4.
//
#ifndef CPP_0687_SOLUTION1_H
#define CPP_0687_SOLUTION1_H

#include "TreeNode.h"

class Solution {
public:

    int ans = 0;

    int dfs(TreeNode *node) {
        if (!node)return 0;

        int leftLen = dfs(node->left);
        int rightLen = dfs(node->right);
        int left = 0, right = 0;
        if (node->left && node->left->val == node->val) {
            left += leftLen + 1;
        }
        if (node->right && node->right->val == node->val) {
            right += rightLen + 1;
        }
        ans = max(ans, left + right);
        // 父节点和子节点不一样， 可以直接返回0， 因为最大同值路径在ans中已经比较了
        return max(left, right);
    }

    int longestUnivaluePath(TreeNode *root) {
        dfs(root);
        return ans;
    }
};

#endif //CPP_0687_SOLUTION1_H

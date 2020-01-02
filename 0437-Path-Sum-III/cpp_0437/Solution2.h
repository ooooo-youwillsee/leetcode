//
// Created by ooooo on 2020/1/2.
//
#ifndef CPP_0437_SOLUTION2_H
#define CPP_0437_SOLUTION2_H

#include "TreeNode.h"
#include <vector>

class Solution {
public:

    // prevSums变为数组可以加速,用一个p标记最后的元素位置。
    int dfs(TreeNode *node, vector<int> prevSums, int sum) {
        if (!node) return 0;

        int count = node->val == sum ? 1 : 0;
        for (int i = 0; i < prevSums.size(); ++i) {
            prevSums[i] += node->val;
            if (prevSums[i] == sum) count++;
        }
        prevSums.push_back(node->val);
        return dfs(node->left, prevSums, sum) + dfs(node->right, prevSums, sum) + count;
    }

    int pathSum(TreeNode *root, int sum) {
        return dfs(root, {}, sum);
    }
};

#endif //CPP_0437_SOLUTION2_H

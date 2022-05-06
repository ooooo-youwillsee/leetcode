//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0637_SOLUTION2_H
#define CPP_0637_SOLUTION2_H

#include "TreeNode.h"
#include <vector>

class Solution {
public:

    /**
     *
     * @param node
     * @param level
     * @param sums  每一层的和
     * @param counts 每一层的个数
     */
    void dfs(TreeNode *node, int level, vector<double> &sums, vector<int> &counts) {
        if (!node) return;

        if (sums.size() < level) {
            sums.push_back(0);
            counts.push_back(0);
        }
        sums[level - 1] += node->val;
        counts[level - 1] += 1;

        dfs(node->left, level + 1, sums, counts);
        dfs(node->right, level + 1, sums, counts);
    }

    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> sums;
        vector<int> counts;
        dfs(root, 1, sums, counts);
        for (int i = 0; i < sums.size(); ++i) {
            sums[i] = sums[i] / counts[i];
        }
        return sums;
    }
};

#endif //CPP_0637_SOLUTION2_H

//
// Created by ooooo on 2020/1/2.
//
#ifndef CPP_0437_SOLUTION1_H
#define CPP_0437_SOLUTION1_H

#include "TreeNode.h"
#include <vector>
#include <queue>

class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;

        queue<TreeNode *> q;
        queue<vector<int>> prevSums;
        int count = 0;
        q.push(root);
        prevSums.push({});
        while (!q.empty()) {
            vector<int> temp;
            TreeNode *node = q.front();
            vector<int> sums = prevSums.front();
            q.pop();
            prevSums.pop();

            if (node->val == sum) count++;
            temp.push_back(node->val);

            for (auto item: sums) {
                int num = item + node->val;
                if (num == sum) count++;
                temp.push_back(num);
            }

            if (node->left) {
                q.push(node->left);
                prevSums.push(temp);
            }
            if (node->right) {
                q.push(node->right);
                prevSums.push(temp);
            }
        }
        return count;
    }
};

#endif //CPP_0437_SOLUTION1_H

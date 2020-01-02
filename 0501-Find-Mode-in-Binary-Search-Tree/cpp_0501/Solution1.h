//
// Created by ooooo on 2020/1/2.
//
#ifndef CPP_0501_SOLUTION1_H
#define CPP_0501_SOLUTION1_H

#include "TreeNode.h"
#include <vector>
#include <unordered_map>

class Solution {

public:

    void dfs(TreeNode *node, unordered_map<int, int> &map, int &maxCount) {
        if (!node) return;
        if (map.count(node->val)) {
            map[node->val] += 1;
        } else {
            map[node->val] = 1;
        }
        maxCount = maxCount > map[node->val] ? maxCount : map[node->val];
        dfs(node->left, map, maxCount);
        dfs(node->right, map, maxCount);
    }


    vector<int> findMode(TreeNode *root) {
        unordered_map<int, int> map;
        int maxCount = 0;
        dfs(root, map, maxCount);
        vector<int> res;
        for (auto entry: map) {
            if (entry.second == maxCount) {
                res.push_back(entry.first);
            }
        }

        return res;
    }
};

#endif //CPP_0501_SOLUTION1_H

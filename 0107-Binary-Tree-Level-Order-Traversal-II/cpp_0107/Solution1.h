//
// Created by ooooo on 2019/12/28.
//
#ifndef CPP_0107_SOLUTION1_H
#define CPP_0107_SOLUTION1_H

#include "TreeNode.h"
#include <stack>
#include <vector>
#include <queue>

class Solution {

private:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> s;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> vec;
            for (int i = 0, len = q.size(); i < len; ++i) {
                TreeNode *node = q.front();
                q.pop();
                vec.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            s.insert(begin(s), vec);
        }
        return s;
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        if (!root) return {};
        return levelOrder(root);
    }
};

#endif //CPP_0107_SOLUTION1_H

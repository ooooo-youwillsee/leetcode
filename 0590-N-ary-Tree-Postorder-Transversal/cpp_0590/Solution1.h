//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0590_SOLUTION1_H
#define CPP_0590_SOLUTION1_H

#include "Node.h"

class Solution {
public:

    void dfs(Node *node, vector<int> &vec) {
        if (!node) return;
        for (auto child: node->children) {
            dfs(child, vec);
        }
        vec.push_back(node->val);
    }

    vector<int> postorder(Node *root) {
        vector<int> vec;
        dfs(root, vec);
        return vec;
    }
};

#endif //CPP_0590_SOLUTION1_H

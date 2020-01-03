//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0589_SOLUTION1_H
#define CPP_0589_SOLUTION1_H

#include "Node.h"

/**
 * recursion
 */
class Solution {
public:

    void help(Node *node, vector<int> &vec) {
        if (!node) return;
        vec.push_back(node->val);
        for (auto child: node->children) {
            help(child, vec);
        }
    }

    vector<int> preorder(Node *root) {
        vector<int> vec;
        help(root, vec);
        return vec;
    }
};

#endif //CPP_0589_SOLUTION1_H

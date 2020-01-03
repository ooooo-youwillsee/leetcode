//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0589_SOLUTION2_H
#define CPP_0589_SOLUTION2_H

#include "Node.h"
#include <stack>

class Solution {
public:
    vector<int> preorder(Node *root) {
        if (!root) return {};
        vector<int> res;
        stack<Node *> s;
        s.push(root);
        while (!s.empty()) {
            Node *node = s.top();
            s.pop();
            res.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; --i) {
                s.push(node->children[i]);
            }
        }
        return res;
    }
};

#endif //CPP_0589_SOLUTION2_H

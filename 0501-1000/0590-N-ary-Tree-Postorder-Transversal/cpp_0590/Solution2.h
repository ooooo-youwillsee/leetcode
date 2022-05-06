//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0590_SOLUTION2_H
#define CPP_0590_SOLUTION2_H

#include "Node.h"
#include <stack>

class Solution {
public:
    vector<int> postorder(Node *root) {
        if(!root) return {};
        stack<Node *> s;
        s.push(root);
        vector<int> res;
        while (!s.empty()) {
            Node *node = s.top();
            s.pop();
            for (auto child: node->children) {
                s.push(child);
            }
            res.push_back(node->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


#endif //CPP_0590_SOLUTION2_H

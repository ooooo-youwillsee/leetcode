//
// Created by ooooo on 2019/12/29.
//
#ifndef CPP_0599_SOLUTION1_H
#define CPP_0599_SOLUTION1_H

#include "Node.h"

class Solution {

private:

    int max = 0;

    void dfs(Node *node, int level) {
        if (!node) return;
        max = max < level ? level : max;
        for (int i = 0; i < node->children.size(); ++i) {
            dfs(node->children[i], level + 1);
        }
    }

public:
    int maxDepth(Node *root) {
        max = 0;
        dfs(root, 1);
        return max;
    }
};

#endif //CPP_0599_SOLUTION1_H

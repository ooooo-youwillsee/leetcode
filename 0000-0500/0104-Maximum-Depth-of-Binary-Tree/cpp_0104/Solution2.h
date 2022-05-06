//
// Created by ooooo on 2019/11/4.
//
#ifndef CPP_0104_SOLUTION2_H
#define CPP_0104_SOLUTION2_H


#include "TreeNode.h"

using namespace std;

class Solution {

public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

#endif //CPP_0104_SOLUTION2_H

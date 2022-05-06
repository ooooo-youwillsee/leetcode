//
// Created by ooooo on 2019/11/1.
//
#ifndef CPP_0098_SOLUTION3_H
#define CPP_0098_SOLUTION3_H

#include "TreeNode.h"
#include <optional>

using namespace std;

class Solution {


private:

    bool help(TreeNode *node, int *min, int *max) {
        if (node == NULL) {
            return true;
        }
        if (min && *min > node->val) return false;
        if (max && *max < node->val) return false;
        return help(node->left, min, &(node->val)) && help(node->right, &(node->val), max);
    }

public:
    bool isValidBST(TreeNode *root) {
        return help(root, NULL, NULL);
    }

};

#endif //CPP_0098_SOLUTION3_H

//
// Created by ooooo on 2019/11/1.
//
#ifndef CPP_0098_SOLUTION2_H
#define CPP_0098_SOLUTION2_H

#include <iostream>
#include "TreeNode.h"

using namespace std;

/**
 * 比较左孩子的val和当前节点的值
 */
class Solution {

private:
    TreeNode *prev;

    bool help(TreeNode *node) {
        if (node == NULL) {
            return true;
        }
        if (!help(node->left)) {
            return false;
        }
        if (this->prev && this->prev->val >= node->val) {
            return false;
        }
        this->prev = node;
        return help(node->right);
    }

public:
    bool isValidBST(TreeNode *root) {
        this->prev = NULL;
        return help(root);
    }

};

#endif //CPP_0098_SOLUTION2_H

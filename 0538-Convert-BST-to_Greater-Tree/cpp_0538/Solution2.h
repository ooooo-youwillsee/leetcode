//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0538_SOLUTION2_H
#define CPP_0538_SOLUTION2_H

#include "TreeNode.h"

class Solution {
public:

    int sum = 0;

    void inOrder(TreeNode *node) {
        if (!node) return;

        inOrder(node->right);
        node->val += sum;
        sum = node->val;
        inOrder(node->left);
    }

    // 最快。。
    TreeNode *convertBST2(TreeNode *root) {
        sum = 0;
        inOrder(root);
        return root;
    }


    TreeNode *convertBST(TreeNode *root) {
        if (!root) return nullptr;
        convertBST(root->right);
        root->val += sum;
        sum = root->val;
        convertBST(root->left);
        return root;
    }
};

#endif //CPP_0538_SOLUTION2_H

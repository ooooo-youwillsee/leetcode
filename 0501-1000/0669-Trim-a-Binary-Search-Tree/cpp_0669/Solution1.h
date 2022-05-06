//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0669_SOLUTION1_H
#define CPP_0669_SOLUTION1_H

#include "TreeNode.h"
#include <vector>


/**
 * leetcode heap-use-after-free  ???
 */
class Solution {
public:

    TreeNode *minimum(TreeNode *node) {
        if (!node->left) return node;
        return minimum(node->left);
    }

    TreeNode *removeMin(TreeNode *node) {
        //!!! return node->right
        if (!node->left) {
            TreeNode *right = node->right;
            node->right = nullptr;
            delete node;
            return right;
        }
        node->left = removeMin(node->left);
        return node;
    }

    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (!root) return nullptr;

        if (root->val < L || root->val > R) {

            if (!root->left) {
                return trimBST(root->right, L, R);
            }
            if (!root->right) {
                return trimBST(root->left, L, R);
            }
            TreeNode *node = new TreeNode(minimum(root->right)->val);
            node->right = removeMin(root->right);
            node->left = root->left;
            delete root;
            return trimBST(node, L, R);
        }

        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

#endif //CPP_0669_SOLUTION1_H

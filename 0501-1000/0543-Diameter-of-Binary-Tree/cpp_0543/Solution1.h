//
// Created by ooooo on 2020/1/3.
//
#ifndef INC_0543_DIAMETER_OF_BINARY_TREE_SOLUTION1_H
#define INC_0543_DIAMETER_OF_BINARY_TREE_SOLUTION1_H

#include "TreeNode.h"

/**
 * 所谓的直径 就是  节点个数  -  1
 */
class Solution {
public:

    int max = INT_MIN;

    int maxDepth(TreeNode *node) {
        if (!node) return 0;
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        if (leftDepth == 0 || rightDepth == 0) {
            max = std::max(std::max(leftDepth, rightDepth), max);
        } else {
            max = std::max(max, leftDepth + rightDepth);
        }
        return std::max(leftDepth, rightDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        maxDepth(root);
        return max == INT_MIN ? 0 : max;
    }
};

#endif //INC_0543_DIAMETER_OF_BINARY_TREE_SOLUTION1_H

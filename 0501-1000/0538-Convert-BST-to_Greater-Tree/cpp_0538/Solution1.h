//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0538_SOLUTION1_H
#define CPP_0538_SOLUTION1_H

#include "TreeNode.h"
#include <vector>

/**
 * vector 存放所有的TreeNode节点(inOrder),倒序遍历。
 */
class Solution {
public:

    void inOrder(TreeNode *node, vector<TreeNode *> &vec) {
        if (!node) return;

        inOrder(node->left, vec);
        vec.push_back(node);
        inOrder(node->right, vec);
    }

    TreeNode *convertBST(TreeNode *root) {
        vector<TreeNode *> vec;
        inOrder(root, vec);
        int num = 0;
        for (int i = vec.size() - 1; i >= 0; --i) {
            vec[i]->val += num;
            num = vec[i]->val;
        }
        return root;
    }
};

#endif //CPP_0538_SOLUTION1_H

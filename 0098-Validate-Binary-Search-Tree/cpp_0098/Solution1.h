//
// Created by ooooo on 2019/11/1.
//
#ifndef CPP_0098_SOLUTION1_H
#define CPP_0098_SOLUTION1_H

#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

/**
 * 对于二叉搜索树， 中序遍历是有序的
 */
class Solution {

private:
    void help(TreeNode *node, vector<int> &vec) {
        if (node == NULL) {
            return;
        }
        help(node->left, vec);
        vec.push_back(node->val);
        help(node->right, vec);
    }

public:
    bool isValidBST(TreeNode *root) {
        vector<int> vec;
        help(root, vec);
        for (int i = 0; !vec.empty() && i < vec.size() - 1; ++i) {
            if (vec[i] >= vec[i + 1]) {
                return false;
            }
        }
        return true;
    }

};

#endif //CPP_0098_SOLUTION1_H

//
// Created by ooooo on 2019/12/31.
//
#ifndef CPP_0938_SOLUTION1_H
#define CPP_0938_SOLUTION1_H

#include "TreeNode.h"

class Solution {

public:


    int rangeSumBST2(TreeNode *root, int L, int R) {
        if (!root) return 0;
        if (root->val < L) return rangeSumBST(root->right, L, R);
        if (root->val > R) return rangeSumBST(root->left, L, R);
        return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) + root->val;
    }


    int rangeSumBST(TreeNode *root, int L, int R) {
        if (!root) return 0;
        int x = root->val >= L && root->val <= R ? root->val : 0;
        return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) + x;
    }

};


#endif //CPP_0938_SOLUTION1_H

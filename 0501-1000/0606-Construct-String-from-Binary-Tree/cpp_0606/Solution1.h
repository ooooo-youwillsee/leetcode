//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0606_SOLUTION1_H
#define CPP_0606_SOLUTION1_H

#include "TreeNode.h"

/**
 * 字符串拼接有点低效， 后序遍历
 */
class Solution {
public:
    string tree2str(TreeNode *t) {
        if (!t) return "";

        string leftStr = tree2str(t->left);
        string rightStr = tree2str(t->right);
        if (leftStr == "" && rightStr == "") return to_string(t->val);
        if (rightStr == "") return to_string(t->val) + "(" + leftStr + ")";
        return to_string(t->val) + "(" + leftStr + ")" + "(" + rightStr + ")";
    }
};

#endif //CPP_0606_SOLUTION1_H

//
// Created by ooooo on 2019/11/1.
//
#ifndef CPP_0098_TREENODE_H
#define CPP_0098_TREENODE_H

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //CPP_0098_TREENODE_H

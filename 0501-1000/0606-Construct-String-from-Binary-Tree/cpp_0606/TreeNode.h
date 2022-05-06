//
// Created by ooooo on 2020/1/3.
//
#ifndef CPP_0606_TREENODE_H
#define CPP_0606_TREENODE_H

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //CPP_0606_TREENODE_H

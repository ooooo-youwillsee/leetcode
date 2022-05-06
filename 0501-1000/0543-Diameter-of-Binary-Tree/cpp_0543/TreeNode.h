//
// Created by ooooo on 2020/1/3.
//
#ifndef INC_0543_DIAMETER_OF_BINARY_TREE_TREENODE_H
#define INC_0543_DIAMETER_OF_BINARY_TREE_TREENODE_H

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //INC_0543_DIAMETER_OF_BINARY_TREE_TREENODE_H

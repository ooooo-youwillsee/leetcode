//
// Created by ooooo on 2019/12/31.
//
#ifndef CPP_0938_TREENODE_H
#define CPP_0938_TREENODE_H

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @return left <= x <= right
 */
bool match(int left, int right, int x){
    return left <= x && x <= right;
}

#endif //CPP_0938_TREENODE_H

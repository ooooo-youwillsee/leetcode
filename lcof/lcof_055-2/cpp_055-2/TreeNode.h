//
// Created by ooooo on 2020/4/11.
//
#ifndef CPP_055_2__TREENODE_H_
#define CPP_055_2__TREENODE_H_

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //CPP_055_2__TREENODE_H_

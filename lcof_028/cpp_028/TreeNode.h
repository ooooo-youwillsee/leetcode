//
// Created by ooooo on 2020/3/18.
//
#ifndef CPP_028__TREENODE_H_
#define CPP_028__TREENODE_H_

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //CPP_028__TREENODE_H_

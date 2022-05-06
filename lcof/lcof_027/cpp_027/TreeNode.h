//
// Created by ooooo on 2020/3/17.
//
#ifndef CPP_027__TREENODE_H_
#define CPP_027__TREENODE_H_

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //CPP_027__TREENODE_H_

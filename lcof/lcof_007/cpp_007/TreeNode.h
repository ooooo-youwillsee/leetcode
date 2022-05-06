//
// Created by ooooo on 2020/3/7.
//
#ifndef CPP_007__TREENODE_H_
#define CPP_007__TREENODE_H_

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

#endif //CPP_007__TREENODE_H_

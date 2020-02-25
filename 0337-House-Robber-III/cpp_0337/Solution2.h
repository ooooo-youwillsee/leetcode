//
// Created by ooooo on 2020/2/25.
//
#ifndef CPP_0337__SOLUTION2_H_
#define CPP_0337__SOLUTION2_H_

#include "TreeNode.h"
#include <unordered_map>

using namespace std;

/**
 * max money = max(根节点 + 四个孙子 ， 两个儿子)
 *      A
 *    /  \
 *   B    B
 *  / \  / \
 * C  C C  C
 *
 * dfs + memo
 */
class Solution {
 public:

  unordered_map<TreeNode *, int> memo;
  int rob(TreeNode *root) {
    if (!root) return 0;
    if (memo.count(root)) return memo[root];
    int money = root->val;
    if (root->left) {
      money += rob(root->left->left) + rob(root->left->right);
    }
    if (root->right) {
      money += rob(root->right->left) + rob(root->right->right);
    }
    money = max(money, rob(root->left) + rob(root->right));
    memo[root] = money;
    return money;
  }
};

#endif //CPP_0337__SOLUTION2_H_

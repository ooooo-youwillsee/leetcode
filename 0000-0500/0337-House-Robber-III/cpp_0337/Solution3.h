//
// Created by ooooo on 2020/2/25.
//
#ifndef CPP_0337__SOLUTION3_H_
#define CPP_0337__SOLUTION3_H_

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
 * dp: 0 表示不偷， 1 表示偷
 *
 * root[0] = max(root.left[0], root.left[1]) + max(root.right[0] , root.right[1])
 * root[1] = root.val + root.left[0] + root.right[0]
 */
class Solution {
 public:

  vector<int> help(TreeNode *node) {
    vector<int> ans(2, 0);
    if (!node) return ans;
    vector<int> l = help(node->left);
    vector<int> r = help(node->right);
    ans[0] = max(l[0], l[1]) + max(r[0], r[1]);
    ans[1] = node->val + l[0] + r[0];
    return ans;
  }

  int rob(TreeNode *root) {
    vector<int> ans = help(root);
    return max(ans[0], ans[1]);
  }
};

#endif //CPP_0337__SOLUTION3_H_

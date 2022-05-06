/**
 * @author ooooo
 * @date 2020/10/29 09:31 
 */

#ifndef CPP_0129__SOLUTION1_H_
#define CPP_0129__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:

	int ans = 0;

	void dfs(TreeNode *node, int cur) {
		if (!node) return;
		cur = cur * 10 + node->val;
		if (!node->left && !node->right) {
			ans += cur;
			return;
		}
		dfs(node->left, cur);
		dfs(node->right, cur);
	}
	int sumNumbers(TreeNode *root) {
		dfs(root, 0);
		return ans;
	}
};

#endif //CPP_0129__SOLUTION1_H_

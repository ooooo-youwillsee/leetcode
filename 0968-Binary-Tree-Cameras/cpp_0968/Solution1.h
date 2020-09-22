/**
 * @author ooooo
 * @date 2020/9/22 11:02 
 */

#ifndef CPP_0968__SOLUTION1_H_
#define CPP_0968__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:

	// 0：已被覆盖
	// 1：需要安装
	// 2: 已安装
	int dfs(TreeNode *node) {
		if (!node) return 0;
		int l = dfs(node->left);
		int r = dfs(node->right);
		if (l == 1 || r == 1) {
			ans +=1;
			return 2;
		}
		if (l == 2 || r == 2) {
			return 0;
		}

		return 1;
	}

	int ans = 0;

	int minCameraCover(TreeNode *root) {
		if (!root) return 0;
		if (dfs(root) == 1) ans ++;
		return ans;
	}
};

#endif //CPP_0968__SOLUTION1_H_

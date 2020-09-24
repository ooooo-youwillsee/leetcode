/**
 * @author ooooo
 * @date 2020/9/24 10:46 
 */

#ifndef CPP_0501__SOLUTION2_H_
#define CPP_0501__SOLUTION2_H_

#include "TreeNode.h"

class Solution {
 public:

	unordered_map<int, int> m;
	int c = 0; // 最高

	void dfs(TreeNode *node) {
		if (!node) return;
		dfs(node->left);
		m[node->val]++;
		c = max(c, m[node->val]);
		dfs(node->right);
	}

	vector<int> findMode(TreeNode *root) {
		dfs(root);
		vector<int> ans;
		for (auto &[k, v]: m) {
			if (c == v) {
				ans.emplace_back(k);
			}
		}
		return ans;
	}
};

#endif //CPP_0501__SOLUTION2_H_

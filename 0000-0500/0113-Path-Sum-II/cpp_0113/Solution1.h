/**
 * @author ooooo
 * @date 2020/9/26 00:13 
 */

#ifndef CPP_0113__SOLUTION1_H_
#define CPP_0113__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:

	void dfs(TreeNode *node, int sum, vector<int> &temp) {
		if (!node) return;
		temp.emplace_back(node->val);
		if (sum == node->val && !node->left && !node->right) {
			ans.push_back(temp);
		}
		sum -= node->val;
		dfs(node->left, sum, temp);
		dfs(node->right, sum, temp);
		temp.pop_back();
	}

	vector<vector<int>> ans;
	vector<vector<int>> pathSum(TreeNode *root, int sum) {
		vector<int> temp;
		dfs(root, sum, temp);
		return ans;
	}
};

#endif //CPP_0113__SOLUTION1_H_

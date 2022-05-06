/**
 * @author ooooo
 * @date 2021/2/17 17:21 
 */

#ifndef CPP_0987__SOLUTION2_H_
#define CPP_0987__SOLUTION2_H_

#include "TreeNode.h"

class Solution {
 public:
	void dfs(TreeNode *root, int col, int row) {
		if (!root) {
			return;
		}
		m[col][row].push_back(root->val);
		dfs(root->left, col - 1, row + 1);
		dfs(root->right, col + 1, row + 1);
	}

	map<int, map<int, vector<int>>> m;

	vector<vector<int>> verticalTraversal(TreeNode *root) {
		if (!root) return {};
		dfs(root, 0, 0);
		vector<vector<int>> ans;
		for (auto &[c, col]:m) {
			vector<int> tmp;
			for (auto &[r, row] :col) {
				sort(row.begin(), row.end());
				tmp.insert(tmp.end(), row.begin(), row.end());
			}
			ans.emplace_back(tmp);
		}
		return ans;
	}
};

#endif //CPP_0987__SOLUTION2_H_

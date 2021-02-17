/**
 * @author ooooo
 * @date 2021/2/17 17:19 
 */

#ifndef CPP_0987__SOLUTION1_H_
#define CPP_0987__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:
	void dfs(TreeNode *root, vector<vector<vector<int>>> &ans, int col, int row) {
		if (!root) {
			return;
		}
		ans[col][row].push_back(root->val);
		dfs(root->left, ans, col - 1, row + 1);
		dfs(root->right, ans, col + 1, row + 1);
	}

	int leftWidth(TreeNode *root) {
		if (!root) {
			return 0;
		}
		return max(1 + leftWidth(root->left), leftWidth(root->right) - 1);
	}

	int rightWidth(TreeNode *root) {
		if (!root) {
			return 0;
		}
		return max(1 + rightWidth(root->right), rightWidth(root->left) - 1);
	}

	int getDepth(TreeNode *root) {
		if (!root) {
			return 0;
		}
		return max(getDepth(root->left), getDepth(root->right)) + 1;
	}

	vector<vector<int>> verticalTraversal(TreeNode *root) {
		if (!root) return {};
		int leftW = leftWidth(root), rightW = rightWidth(root), h = getDepth(root);
		vector<vector<vector<int>>> ans(leftW + rightW - 1, vector<vector<int>>(h, vector<int>()));
		dfs(root, ans, leftW - 1, 0);
		vector<vector<int>> res(leftW + rightW - 1);
		for (int i = 0; i < ans.size(); ++i) {
			auto &cols = ans[i];
			for (auto &row: cols) {
				sort(row.begin(), row.end());
				for (auto num: row) {
					res[i].push_back(num);
				}
			}
		}
		return res;
	}
};

#endif //CPP_0987__SOLUTION1_H_

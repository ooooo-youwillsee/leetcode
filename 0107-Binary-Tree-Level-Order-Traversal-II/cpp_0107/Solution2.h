/**
 * @author ooooo
 * @date 2020/9/6 01:06
 */

#ifndef CPP_0107__SOLUTION2_H_
#define CPP_0107__SOLUTION2_H_


#include <iostream>
#include <vector>
#include "TreeNode.h"
#include <queue>

using namespace std;

class Solution2 {

 public:
	vector<vector<int>> levelOrderBottom(TreeNode *root) {
		if(!root) return {};
		vector<vector<int>> ans;
		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty()) {
			ans.push_back({});
			for (int i = 0, sz = q.size(); i < sz; ++i) {
				TreeNode *node = q.front();
				q.pop();
				ans[ans.size() - 1].push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}

};

#endif //CPP_0107__SOLUTION2_H_

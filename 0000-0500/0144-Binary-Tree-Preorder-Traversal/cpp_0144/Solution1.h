/**
 * @author ooooo
 * @date 2020/9/25 23:15 
 */

#ifndef CPP_0144__SOLUTION1_H_
#define CPP_0144__SOLUTION1_H_

#include "TreeNode.h"

/**
 * color mark
 */
class Solution {
 public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> ans;
		if (!root) return ans;
		stack<pair<TreeNode *, bool>> s;
		s.push({root, false});
		while (!s.empty()) {
			auto[node, visited] = s.top();
			s.pop();
			if (visited) {
				ans.emplace_back(node->val);
			} else {
				if (node->right) s.push({node->right, false});
				if (node->left) s.push({node->left, false});
				s.push({node, true});
			}
		}
		return ans;
	}
};

#endif //CPP_0144__SOLUTION1_H_

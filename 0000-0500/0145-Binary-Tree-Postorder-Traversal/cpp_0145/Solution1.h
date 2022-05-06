/**
 * @author ooooo
 * @date 2020/9/25 23:34 
 */

#ifndef CPP_0145__SOLUTION1_H_
#define CPP_0145__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:
	vector<int> postorderTraversal(TreeNode *root) {
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
				s.push({node, true});
				if (node->right) s.push({node->right, false});
				if (node->left) s.push({node->left, false});
			}
		}
		return ans;
	}
};

#endif //CPP_0145__SOLUTION1_H_

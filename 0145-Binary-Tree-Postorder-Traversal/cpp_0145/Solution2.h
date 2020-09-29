/**
 * @author ooooo
 * @date 2020/9/29 09:21 
 */

#ifndef CPP_0145__SOLUTION2_H_
#define CPP_0145__SOLUTION2_H_

#include "TreeNode.h"

class Solution {
 public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ans;
		if (!root) return ans;
		stack<TreeNode *> s;
		TreeNode *cur = root, *prev = nullptr;
		while (!s.empty() || cur) {
			if (cur) {
				s.push(cur);
				cur = cur->left;
			} else {
				auto x = s.top();
				if (x->right && x->right != prev) {
					cur = x->right;
				} else {
					s.pop();
					prev = x;
					ans.emplace_back(x->val);
				}
			}
		}

		return ans;
	}
};

#endif //CPP_0145__SOLUTION2_H_

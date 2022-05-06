/**
 * @author ooooo
 * @date 2020/9/14 18:19 
 */

#ifndef CPP_0094__SOLUTION4_H_
#define CPP_0094__SOLUTION4_H_

#include "TreeNode.h"
#include <stack>

/**
 * color marker
 */
class Solution {
 public:

	vector<int> inorderTraversal(TreeNode *root) {
		stack<pair<TreeNode *, bool>> s;
		s.push({root, false});
		vector<int> ans;
		while (!s.empty()) {
			auto node = s.top().first;
			auto flag = s.top().second;
			s.pop();
			if (flag) {
				ans.push_back(node->val);
			} else {
				if (node->right) {
					s.push({node->right, false});
				}
				s.push({node, true});
				if (node->left) {
					s.push({node->left, false});
				}
			}
		}
		return ans;
	}
};

#endif //CPP_0094__SOLUTION4_H_

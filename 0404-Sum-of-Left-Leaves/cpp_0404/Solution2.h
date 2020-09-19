/**
 * @author ooooo
 * @date 2020/9/19 13:38 
 */

#ifndef CPP_0404__SOLUTION2_H_
#define CPP_0404__SOLUTION2_H_

#include "TreeNode.h"

class Solution {
 public:

	int sumOfLeftLeaves(TreeNode *root, bool is_left) {
		if (!root) return 0;
		if (is_left && !root->left && !root->right) return root->val;
		return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
	}

	int sumOfLeftLeaves(TreeNode *root) {
		return sumOfLeftLeaves(root, false);
	}
};

#endif //CPP_0404__SOLUTION2_H_

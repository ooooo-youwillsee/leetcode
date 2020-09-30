/**
 * @author ooooo
 * @date 2020/9/30 09:17 
 */

#ifndef CPP_0701__SOLUTION1_H_
#define CPP_0701__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:
	TreeNode *insertIntoBST(TreeNode *root, int val) {
		if (!root) return new TreeNode(val);
		if (root->val < val) {
			root->right = insertIntoBST(root->right, val);
		} else if (root->val > val) {
			root->left = insertIntoBST(root->left, val);
		}
		return root;
	}
};

#endif //CPP_0701__SOLUTION1_H_

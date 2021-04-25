/**
 * @author ooooo
 * @date 2021/4/25 09:47 
 */

#ifndef CPP_0897__SOLUTION2_H_
#define CPP_0897__SOLUTION2_H_

#include "TreeNode.h"

class Solution {
 public:
	TreeNode *increasingBST(TreeNode *root) {
		if (!root) return nullptr;
		if (!root->left && !root->right) return root;
		TreeNode *l = increasingBST(root->left);
		TreeNode *r = increasingBST(root->right);
		root->left = nullptr;
		root->right = r;
		if (!l) return root;
		TreeNode *node = l;
		while (node->right) {
			node = node->right;
		}
		node->right = root;
		return l;
	}
};

#endif //CPP_0897__SOLUTION2_H_

/**
 * @author ooooo
 * @date 2020/9/21 13:16 
 */

#ifndef CPP_0538__SOLUTION3_H_
#define CPP_0538__SOLUTION3_H_

#include "TreeNode.h"

class Solution {
 public:

	TreeNode *prev;

	TreeNode *convertBST(TreeNode *root) {
		if (!root) return root;
		convertBST(root->right);
		if (!prev) {
			prev = root;
		} else {
			root->val += prev->val;
			prev = root;
		}
		convertBST(root->left);
		return root;
	}
};

#endif //CPP_0538__SOLUTION3_H_

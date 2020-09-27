/**
 * @author ooooo
 * @date 2020/9/27 11:04 
 */

#ifndef CPP_0235__SOLUTION2_H_
#define CPP_0235__SOLUTION2_H_

#include "TreeNode.h"

class Solution {
 public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		if (root->val > p->val && root->val > q->val) {
			return lowestCommonAncestor(root->left, p, q);
		}
		if (root->val < p->val && root->val < q->val) {
			return lowestCommonAncestor(root->right, p, q);
		}
		return root;
	}

};

#endif //CPP_0235__SOLUTION2_H_

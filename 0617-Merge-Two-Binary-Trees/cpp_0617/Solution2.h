/**
 * @author ooooo
 * @date 2020/9/23 10:12 
 */

#ifndef CPP_0617__SOLUTION2_H_
#define CPP_0617__SOLUTION2_H_

#include "TreeNode.h"

class Solution {
 public:
	TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
		if (!t1) return t2;
		if (!t2) return t1;
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
};

#endif //CPP_0617__SOLUTION2_H_

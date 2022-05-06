/**
 * @author ooooo
 * @date 2020/11/24 09:07 
 */

#ifndef CPP_0222__SOLUTION1_H_
#define CPP_0222__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:
	int countNodes(TreeNode *root) {
		if (root == nullptr) return 0;
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};

#endif //CPP_0222__SOLUTION1_H_

/**
 * @author ooooo
 * @date 2020/10/11 13:41 
 */

#ifndef CPP_1609__SOLUTION1_H_
#define CPP_1609__SOLUTION1_H_

#include "TreeNode.h"

bool isEvenOddTree(TreeNode *root) {
	queue<TreeNode *> q;
	q.push(root);
	int level = 0;
	while (!q.empty()) {
		bool incr = level % 2 == 0;
		int val = incr ? 0 : 10000000;
		for (int size = q.size(); size > 0; size--) {
			TreeNode *node = q.front();
			q.pop();
			if (incr) {
				if (node->val <= val || node->val % 2 == 0) return false;
			} else {
				if (node->val >= val || node->val % 2 == 1) return false;
			}
			val = node->val;

			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		level++;
	}
	return true;
}

#endif //CPP_1609__SOLUTION1_H_

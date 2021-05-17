/**
 * @author ooooo
 * @date 2021/5/17 21:58 
 */

#ifndef CPP_0993__SOLUTION3_H_
#define CPP_0993__SOLUTION3_H_

#include "TreeNode.h"
#include <iostream>
#include <queue>

using namespace std;

class Solution {
 public:

	bool isCousins(TreeNode *root, int x, int y) {
		if (!root) return false;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			bool isX = false, isY = false;
			for (int i = 0, sz = q.size(); i < sz; i++) {
				TreeNode *node = q.front();
				q.pop();
				if (node->val == x) isX = true;
				if (node->val == y) isY = true;
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
				if (node->left && node->right) {
					if (node->left->val == x && node->right->val == y) return false;
					if (node->right->val == x && node->left->val == y) return false;
				}
			}
			if (isX && isY) return true;
			if ((isX && !isY) || (!isX && isY)) return false;
		}
		return false;
	}
};

#endif //CPP_0993__SOLUTION3_H_

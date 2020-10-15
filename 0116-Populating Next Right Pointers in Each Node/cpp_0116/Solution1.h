/**
 * @author ooooo
 * @date 2020/10/15 19:35 
 */

#ifndef CPP_0116__SOLUTION1_H_
#define CPP_0116__SOLUTION1_H_

#include "Node.h"

class Solution {
 public:

	Node *getNode(Node *node) {
		if (!node) return nullptr;
		if (node->left) return node->left;
		if (node->right) return node->right;
		return getNode(node->next);
	}

	Node *connect(Node *root) {
		if (!root) return root;
		if (!root->left && !root->right) return root;
		root->left->next = root->right ? root->right : getNode(root->next);
		root->right->next = getNode(root->next);
		connect(root->right);
		connect(root->left);
		return root;
	}
};

#endif //CPP_0116__SOLUTION1_H_

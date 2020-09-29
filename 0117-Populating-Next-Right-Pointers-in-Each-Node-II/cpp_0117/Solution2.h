/**
 * @author ooooo
 * @date 2020/9/28 09:27 
 */

#ifndef CPP_0117__SOLUTION2_H_
#define CPP_0117__SOLUTION2_H_

#include "Node.h"

/**
 * recursion
 */
class Solution {
 public:

	Node *getNextNode(Node *p_node) {
		while (p_node) {
			if (p_node->left) return p_node->left;
			if (p_node->right) return p_node->right;
			p_node = p_node->next;
		}
		return nullptr;
	}
	Node *connect(Node *root) {
		if (!root) return root;
		if (root->left) {
			if (root->right) {
				root->left->next = root->right;
			} else {
				root->left->next = getNextNode(root->next);
			}
		}
		if (root->right) {
			root->right->next = getNextNode(root->next);
		}

		connect(root->right);
		connect(root->left);
		return root;
	}
};

#endif //CPP_0117__SOLUTION2_H_

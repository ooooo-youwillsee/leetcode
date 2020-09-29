#include <iostream>
#include "Solution2.h"

int main() {

	Node *root = new Node(3);
	root->left = new Node(9);
	root->right = new Node(20);
	root->right->left = new Node(15);
	root->right->right = new Node(7);

	Solution solution;
	solution.connect(root);
	return 0;
}

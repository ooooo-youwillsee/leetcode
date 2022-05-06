#include <iostream>
#include "Solution2.h"

int main() {

	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);

	Solution solution;
	auto ans = solution.postorderTraversal(root);
	for (auto &val : ans) {
		cout << val << " " << endl;
	}
	return 0;
}

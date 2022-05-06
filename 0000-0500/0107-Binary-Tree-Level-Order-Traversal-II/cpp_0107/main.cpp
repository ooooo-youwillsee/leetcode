#include <iostream>
#include "Solution2.h"

int main() {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	Solution2 solution_2;
	const vector<vector<int>> &vec = solution_2.levelOrderBottom(root);
	for (auto &group: vec) {
		for (auto g: group) cout << g << " ";
		cout << endl;
	}
	return 0;
}
/**
 * @author ooooo
 * @date 2020/9/25 09:24 
 */

#ifndef CPP_0106__SOLUTION1_H_
#define CPP_0106__SOLUTION1_H_

#include "TreeNode.h"

class Solution {
 public:

	vector<int> postorder;
	int k; // 后序位置，用于判断根节点

	TreeNode *dfs(int i, int j) {
		if (i > j) return NULL;
		int val = postorder[k--];
		TreeNode *node = new TreeNode(val);
		int cur_index = index_map[val];
		node->right = dfs(cur_index + 1, j);
		node->left = dfs(i, cur_index - 1);
		return node;
	}

	unordered_map<int, int> index_map;

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		this->postorder = postorder;
		for (int i = 0; i < inorder.size(); ++i) {
			index_map[inorder[i]] = i;
		}
		k = postorder.size() - 1;
		return dfs(0, inorder.size() - 1);
	}
};

#endif //CPP_0106__SOLUTION1_H_

/**
 * @author ooooo
 * @date 2021/3/12 10:17 
 */

#ifndef CPP_0331__SOLUTION1_H_
#define CPP_0331__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	struct Node {
		Node *left, *right;
		int value;

		Node(int value) : value(value) {
			this->left = this->right = nullptr;
		}
	};

	Node *dfs(string &preorder) {
		if (i >= preorder.size() || !pass) return nullptr;
		if (preorder[i] == '#') {
			i += 2;
			return new Node(-1);
		}
		int num = 0;
		while (i < preorder.size() && preorder[i] >= '0' && preorder[i] <= '9') {
			num = num * 10 + (preorder[i] - '0');
			i++;
		}
		i++;
		Node *root = new Node(num);
		root->left = dfs(preorder);
		root->right = dfs(preorder);
		if (!root->left || !root->right) {
			pass = false;
		}
		return root;
	}

	int i = 0;
	bool pass = false;

	bool isValidSerialization(string preorder) {
		i = 0;
		pass = true;
		dfs(preorder);
		return i == preorder.size() && pass;
	}
};

#endif //CPP_0331__SOLUTION1_H_

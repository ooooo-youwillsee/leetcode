/**
 * @author ooooo
 * @date 2021/3/28 09:44 
 */

#ifndef CPP_0173__SOLUTION1_H_
#define CPP_0173__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
 public:
	stack<TreeNode *> s;

	BSTIterator(TreeNode *root) {
		if (!root) {
			return;
		}
		TreeNode *cur = root;
		while (cur) {
			s.push(cur);
			cur = cur->left;
		}
	}

	int next() {
		TreeNode *node = s.top();
		s.pop();
		TreeNode *cur = node->right;
		while (cur) {
			s.push(cur);
			cur = cur->left;
		}
		return node->val;
	}

	bool hasNext() {
		return !s.empty();
	}
};

#endif //CPP_0173__SOLUTION1_H_

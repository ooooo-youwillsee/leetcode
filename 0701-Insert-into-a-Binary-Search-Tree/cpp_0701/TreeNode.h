/**
 * @author ooooo
 * @date 2020/9/30 09:16 
 */

#ifndef CPP_0701__TREENODE_H_
#define CPP_0701__TREENODE_H_

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //CPP_0701__TREENODE_H_

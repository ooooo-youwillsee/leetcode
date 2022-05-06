/**
 * @author ooooo
 * @date 2020/9/25 23:33 
 */

#ifndef CPP_0145__TREENODE_H_
#define CPP_0145__TREENODE_H_

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

#endif //CPP_0145__TREENODE_H_

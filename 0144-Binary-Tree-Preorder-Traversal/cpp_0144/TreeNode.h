/**
 * @author ooooo
 * @date 2020/9/25 23:15 
 */

#ifndef CPP_0144__TREENODE_H_
#define CPP_0144__TREENODE_H_

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //CPP_0144__TREENODE_H_

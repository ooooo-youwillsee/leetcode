/**
 * @author ooooo
 * @date 2020/9/22 11:01 
 */

#ifndef CPP_0968__TREENODE_H_
#define CPP_0968__TREENODE_H_

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //CPP_0968__TREENODE_H_

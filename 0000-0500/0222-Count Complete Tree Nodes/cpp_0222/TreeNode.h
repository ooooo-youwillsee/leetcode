/**
 * @author ooooo
 * @date 2020/11/24 09:08 
 */

#ifndef CPP_0222__TREENODE_H_
#define CPP_0222__TREENODE_H_

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //CPP_0222__TREENODE_H_

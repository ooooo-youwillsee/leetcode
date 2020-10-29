/**
 * @author ooooo
 * @date 2020/10/29 09:31 
 */

#ifndef CPP_0129__TREENODE_H_
#define CPP_0129__TREENODE_H_

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //CPP_0129__TREENODE_H_

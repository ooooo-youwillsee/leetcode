/**
 * @author ooooo
 * @date 2020/9/26 00:12 
 */

#ifndef CPP_0113__TREENODE_H_
#define CPP_0113__TREENODE_H_

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //CPP_0113__TREENODE_H_

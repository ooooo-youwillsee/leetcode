/**
 * @author ooooo
 * @date 2020/9/25 09:24 
 */

#ifndef CPP_0106__TREENODE_H_
#define CPP_0106__TREENODE_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //CPP_0106__TREENODE_H_

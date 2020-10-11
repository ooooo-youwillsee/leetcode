/**
 * @author ooooo
 * @date 2020/10/11 13:42 
 */

#ifndef CPP_1609__TREENODE_H_
#define CPP_1609__TREENODE_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //CPP_1609__TREENODE_H_

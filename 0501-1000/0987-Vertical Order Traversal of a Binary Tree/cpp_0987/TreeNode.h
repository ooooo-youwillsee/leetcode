/**
 * @author ooooo
 * @date 2021/2/17 17:19 
 */

#ifndef CPP_0987__TREENODE_H_
#define CPP_0987__TREENODE_H_

#include <vector>
#include <map>
#include <set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //CPP_0987__TREENODE_H_

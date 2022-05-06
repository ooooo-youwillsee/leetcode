/**
 * @author ooooo
 * @date 2020/9/12 10:44 
 */

#ifndef CPP_0637__SOLUTION3_H_
#define CPP_0637__SOLUTION3_H_

#include "TreeNode.h"

class Solution3 {

 public:
	vector<double> averageOfLevels(TreeNode *root) {
		vector<double> ans;
		if (!root) return ans;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			double sum = 0, len = q.size();
			for (int i = 0; i < len; ++i) {
				auto node = q.front();
				sum += node->val;
				q.pop();
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			ans.push_back(sum / len);
		}
		return ans;
	}
};

#endif //CPP_0637__SOLUTION3_H_

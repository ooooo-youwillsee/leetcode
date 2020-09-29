/**
 * @author ooooo
 * @date 2020/9/28 09:19 
 */

#ifndef CPP_0117__SOLUTION1_H_
#define CPP_0117__SOLUTION1_H_

#include "Node.h"

class Solution {
 public:
	Node *connect(Node *root) {
		if (!root) return root;
		queue<Node *> q;
		q.push(root);
		vector<vector<Node *>> rows;
		while (!q.empty()) {
			vector<Node *> row;
			for (int i = 0, len = q.size(); i < len; ++i) {
				auto node = q.front();
				q.pop();
				row.emplace_back(node);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			rows.emplace_back(row);
		}
		for (auto &row :rows) {
			for (int i = 0; i < row.size() - 1; ++i) {
				row[i]->next = row[i + 1];
			}
		}
		return root;
	}
};

#endif //CPP_0117__SOLUTION1_H_

/**
 * @author ooooo
 * @date 2021/5/23 22:03 
 */

#ifndef CPP_1707__SOLUTION1_H_
#define CPP_1707__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

/**
 * 排序 + Trie
 */
class Solution {
 public:

	struct Node {
		Node *next[2] = {nullptr};
	};

	Node *root = new Node();

	void build(int num) {
		Node *cur = root;
		for (int i = 0; i < 32; i++) {
			int bit = num & (1 << (31 - i));
			if (bit) {
				if (!cur->next[1]) {
					cur->next[1] = new Node();
				}
				cur = cur->next[1];
			} else {
				if (!cur->next[0]) {
					cur->next[0] = new Node();
				}
				cur = cur->next[0];
			}
		}
	}

	int help(int x) {
		Node *cur = root;
		int ans = 0;
		for (int i = 0; i < 32; i++) {
			int bit = x & (1 << (31 - i));
			if (bit) {
				if (cur->next[0]) {
					cur = cur->next[0];
					ans |= (1 << (31 - i));
				} else {
					cur = cur->next[1];
				}
			} else {
				if (cur->next[1]) {
					cur = cur->next[1];
					ans |= (1 << (31 - i));
				} else {
					cur = cur->next[0];
				}
			}
		}
		return ans;
	}

	vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
		sort(nums.begin(), nums.end());
		int i = 0;
		int n = queries.size();
		vector<int> ans(n);
		vector<int> indexes(n);
		for (int k = 0; k < n; k++) {
			indexes[k] = k;
		}
		sort(indexes.begin(), indexes.end(), [&](const int x, const int y) {
			return queries[x][1] < queries[y][1];
		});

		for (int k = 0; k < n; k++) {
			int x1 = queries[indexes[k]][0], m1 = queries[indexes[k]][1];
			while (i < nums.size() && nums[i] <= m1) {
				build(nums[i]);
				i++;
			}
			if (m1 < nums[0]) {
				ans[indexes[k]] = -1;
			} else {
				ans[indexes[k]] = help(x1);
			}
		}

		return ans;
	}
};

#endif //CPP_1707__SOLUTION1_H_

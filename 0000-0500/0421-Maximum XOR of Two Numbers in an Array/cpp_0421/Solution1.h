/**
 * @author ooooo
 * @date 2021/5/16 09:30 
 */

#ifndef CPP_0421__SOLUTION1_H_
#define CPP_0421__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	struct Node {
		vector<Node *> children;
		Node() : children(2) {
		}
	};

	Node *root;
	void build(int num) {
		Node *cur = root;
		for (int i = 0; i < 32; i++) {
			if (num & (1 << (31 - i))) {
				if (!cur->children[1]) {
					cur->children[1] = new Node();
				}
				cur = cur->children[1];
			} else {
				if (!cur->children[0]) {
					cur->children[0] = new Node();
				}
				cur = cur->children[0];
			}
		}
	}

	int findMaximumXOR(vector<int> &nums) {
		root = new Node();
		for (auto num :nums) {
			build(num);
		}

		int ans = 0;
		for (auto num: nums) {
			Node *cur = root;
			int x = 0;
			for (int i = 0; i < 32; i++) {
				int bit = num & (1 << (31 - i));

				if (bit) {
					if (cur->children[0]) {
						cur = cur->children[0];
						x |= (1 << (31 - i));
					} else {
						cur = cur->children[1];
					}
				} else {
					if (cur->children[1]) {
						cur = cur->children[1];
						x |= (1 << (31 - i));
					} else {
						cur = cur->children[0];
					}
				}
				if (!cur) {
					break;
				}
			}
			ans = max(ans, x);
		}
		return ans;
	}
};
#endif //CPP_0421__SOLUTION1_H_

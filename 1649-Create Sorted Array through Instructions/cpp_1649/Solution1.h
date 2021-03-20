/**
 * @author ooooo
 * @date 2021/3/20 12:34 
 */

#ifndef CPP_1649__SOLUTION1_H_
#define CPP_1649__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

// 线段树
class Solution {
 public:

	struct SegTree {
		vector<int> data, tree;
		SegTree(vector<int> data) : data(data.size()), tree(data.size() * 4) {
			for (int i = 0; i < data.size(); ++i) {
				this->data[i] = data[i];
			}
			if (!data.empty()) {
				build(0, 0, data.size() - 1);
			}
		}

		void build(int root, int l, int r) {
			if (l > r) return;
			if (l == r) {
				tree[root] = data[l];
				return;
			}
			int mid = l + (r - l) / 2;
			build(left(root), l, mid);
			build(right(root), mid + 1, r);
			tree[root] = merge(tree[left(root)], tree[right(root)]);
		}

		int query(int ql, int qr) {
			return query(0, 0, data.size() - 1, ql, qr);
		}

		int query(int root, int l, int r, int ql, int qr) {
			if (ql < l || r < qr) return 0;
			if (l == ql && r == qr) {
				return tree[root];
			}
			int mid = l + (r - l) / 2;
			if (qr <= mid) {
				return query(left(root), l, mid, ql, qr);
			} else if (ql > mid) {
				return query(right(root), mid + 1, r, ql, qr);
			} else {
				return merge(query(left(root), l, mid, ql, mid), query(right(root), mid + 1, r, mid + 1, qr));
			}
		}

		void set(int i, int v) {
			set(0, 0, data.size() - 1, i, v);
		}

		void set(int root, int l, int r, int i, int v) {
			if (l == r && l == i) {
				tree[root] = v;
				return;
			}
			int mid = l + (r - l) / 2;
			if (i <= mid) {
				set(left(root), l, mid, i, v);
			} else if (i > mid) {
				set(right(root), mid + 1, r, i, v);
			}
			tree[root] = merge(tree[left(root)], tree[right(root)]);
		}

		int left(int root) {
			return 2 * root + 1;
		}

		int right(int root) {
			return 2 * root + 2;
		}

		int merge(int x, int y) {
			return x + y;
		}
	};

	static constexpr int MOD = 1e9 + 7;
	int createSortedArray(vector<int> &instructions) {
		vector<int> nums(1e5 + 1);
		SegTree tree(nums);

		long long ans = 0;
		for (int i = 0; i < instructions.size(); ++i) {
			int less = tree.query(0, instructions[i] - 1);
			int greater = i - nums[instructions[i]] - less;
			ans = (ans + min(less, greater)) % MOD;
			nums[instructions[i]]++;
			tree.set(instructions[i], nums[instructions[i]]);
		}

		return ans;
	}
};

#endif //CPP_1649__SOLUTION1_H_

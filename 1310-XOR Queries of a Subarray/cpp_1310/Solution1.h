/**
 * @author ooooo
 * @date 2021/5/12 19:44 
 */

#ifndef CPP_1310__SOLUTION1_H_
#define CPP_1310__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	struct SegmentTree {

		vector<int> tree;
		vector<int> arr;
		SegmentTree(vector<int> arr) {
			tree.assign(4 * arr.size(), 0);
			this->arr = arr;
			buildTree(0, 0, arr.size() - 1);
		}

		void buildTree(int root, int l, int r) {
			if (l > r) return;
			if (l == r) {
				tree[root] = arr[l];
				return;
			}
			int mid = l + (r - l) / 2;
			buildTree(lc(root), l, mid);
			buildTree(rc(root), mid + 1, r);
			tree[root] = merge(tree[lc(root)], tree[rc(root)]);
		}

		int query(int ql, int qr) {
			return query(0, 0, arr.size() - 1, ql, qr);
		}

		int query(int root, int l, int r, int ql, int qr) {
			if (ql > qr) return 0;
			if (l == ql && r == qr) {
				return tree[root];
			}
			int mid = l + (r - l) / 2;
			if (qr <= mid) {
				return query(lc(root), l, mid, ql, qr);
			} else if (mid + 1 <= ql) {
				return query(rc(root), mid + 1, r, ql, qr);
			}
			int lv = query(lc(root), l, mid, ql, mid);
			int rv = query(rc(root), mid + 1, r, mid + 1, qr);
			return merge(lv, rv);
		}

		int merge(int x, int y) {
			return x ^ y;
		}

		int lc(int x) {
			return 2 * x + 1;
		}

		int rc(int x) {
			return 2 * x + 2;
		}
	};
	vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
		vector<int> ans;
		SegmentTree t(arr);
		for (auto &q: queries) {
			ans.push_back(t.query(q[0], q[1]));
		}
		return ans;
	}
};

#endif //CPP_1310__SOLUTION1_H_

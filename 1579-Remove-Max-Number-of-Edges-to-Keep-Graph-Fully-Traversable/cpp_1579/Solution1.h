/**
 * @author ooooo
 * @date 2020/9/26 00:41 
 */

#ifndef CPP_1579__SOLUTION1_H_
#define CPP_1579__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	// union find ( path zipå)
	int find(vector<int> &p, int i) {
		int t = i;
		while (i != p[i]) {
			i = p[i];
		}
		while (t != p[t]) {
			int tmp = p[t];
			p[t] = i;
			t = tmp;
		}
		return i;
	}

	bool merge(vector<int> &p, int u, int v) {
		int pu = find(p, u);
		int pv = find(p, v);
		if (pu == pv) return true;
		p[pu] = pv;
		return false;
	}

	int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
		int del = 0, cnt1 = n, cnt2 = n;
		vector<int> p1(n + 1), p2;
		for (int i = 0; i < n + 1; ++i) {
			p1[i] = i;
		}

		for (int i = 0; i < edges.size(); ++i) {
			int type = edges[i][0], u = edges[i][1], v = edges[i][2];
			if (type == 3) {
				if (merge(p1, u, v)) {
					del++;
				} else {
					cnt1--;
				}
			}
		}
		// 赋相同值
		p2 = p1;
		cnt2 = cnt1;

		for (int i = 0; i < edges.size(); ++i) {
			int type = edges[i][0], u = edges[i][1], v = edges[i][2];
			if (type == 1) {
				if (merge(p1, u, v)) {
					del++;
				} else {
					cnt1--;
				}
			} else if (type == 2) {
				if (merge(p2, u, v)) {
					del++;
				} else {
					cnt2--;
				}
			}
		}

		if (cnt1 != 1 || cnt2 != 1) return -1;
		return del;
	}
};

#endif //CPP_1579__SOLUTION1_H_

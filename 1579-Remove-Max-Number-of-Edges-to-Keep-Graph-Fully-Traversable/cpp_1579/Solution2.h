/**
 * @author ooooo
 * @date 2021/1/27 14:16 
 */

#ifndef CPP_1579__SOLUTION2_H_
#define CPP_1579__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	class UF {
	 public:
		int n;
		vector<int> p;

		UF(int n) : n(n), p(n) {
			for (int i = 0; i < n; ++i) {
				p[i] = i;
			}
		}

		int find(int i) {
			if (p[i] == i) return i;
			return p[i] = find(p[i]);
		}

		bool connected(int i, int j) {
			int pi = find(i), pj = find(j);
			if (pi == pj) return true;
			p[pi] = pj;
			n--;
			return false;
		}

		int getSize() {
			return n - 1;
		}

	};

	int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
		vector<vector<int>> aEdges, bEdges;
		UF a(n + 1), b(n + 1);

		int needDelete = 0;

		for (auto &edge: edges) {
			int t = edge[0], u = edge[1], v = edge[2];
			if (t == 3) {
				a.connected(u, v);
				if (b.connected(u, v)) needDelete++;
			} else if (t == 1) {
				aEdges.push_back({u, v});
			} else if (t == 2) {
				bEdges.push_back({u, v});
			}
		}


		for (auto &edge: aEdges) {
			int u = edge[0], v = edge[1];
			if (a.connected(u, v)) {
				needDelete++;
			}
		}

		if (a.getSize() != 1) return -1;

		for (auto &edge: bEdges) {
			int u = edge[0], v = edge[1];
			if (b.connected(u, v)) {
				needDelete++;
			}
		}

		if (b.getSize() != 1) return -1;

		return needDelete;
	}
};

#endif //CPP_1579__SOLUTION2_H_

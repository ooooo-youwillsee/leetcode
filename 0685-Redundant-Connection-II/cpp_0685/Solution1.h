/**
 * @author ooooo
 * @date 2020/9/17 18:47 
 */

#ifndef CPP_0685__SOLUTION1_H_
#define CPP_0685__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
 public:

	int find(vector<int> uf, int i) {
		while (uf[i] != i) {
			i = uf[i];
		}
		return i;
	}

	vector<int> findRedundantDirectedConnection(vector<vector<int>> edges) {
		int n = edges.size();
		vector<int> uf(n + 1);
		vector<int> p(n + 1);
		for (int i = 1; i < n + 1; i++) {
			uf[i] = p[i] = i;
		}
		int conflict = -1, cyclic = -1;
		for (int i = 0; i < edges.size(); ++i) {
			vector<int> edge = edges[i];
			int u = edge[0], v = edge[1];
			if (p[v] != v) {
				conflict = i;
			} else {
				p[v] = u;
				int up = find(uf, u), vp = find(uf, v);
				if (vp == up) {
					cyclic = i;
				} else {
					uf[vp] = up;
				}
			}
		}

		if (conflict == -1) {
			return edges[cyclic];
		} else {
			auto x = edges[conflict];
			return cyclic == -1 ? x : vector<int>{p[x[1]], x[1]};
		}
	}
};

#endif //CPP_0685__SOLUTION1_H_

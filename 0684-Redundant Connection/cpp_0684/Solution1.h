/**
 * @author ooooo
 * @date 2021/1/13 20:10 
 */

#ifndef CPP_0684__SOLUTION1_H_
#define CPP_0684__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	vector<int> findRedundantConnection(vector<vector<int>> &edges) {
		int n = edges.size();
		vector<int> p(n + 1), rank(n + 1, 1);
		for (int i = 0; i < n + 1; ++i) {
			p[i] = i;
		}

		vector<int> ans;
		for (int i = 0; i < edges.size(); ++i) {
			int u = edges[i][0], v = edges[i][1];
			if (connected(p, rank, u, v)) {
				ans = edges[i];
			}
		}
		return ans;
	}

	int find(vector<int> &p, int i) {
		if (p[i] == i) return i;
		return p[i] = find(p, p[i]);
	}

	bool connected(vector<int> &p, vector<int> &rank, int i, int j) {
		int pi = find(p, i), pj = find(p, j);
		if (pi == pj) return true;
		if (rank[pi] == rank[pj]) {
			p[pi] = pj;
			rank[pj]++;
		} else if (rank[pi] < rank[pj]) {
			p[pi] = pj;
		} else {
			p[pj] = pi;
		}
		return false;
	}
};

#endif //CPP_0684__SOLUTION1_H_

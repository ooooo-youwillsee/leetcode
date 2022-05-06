/**
 * @author ooooo
 * @date 2021/1/19 20:12 
 */

#ifndef CPP_1584__SOLUTION1_H_
#define CPP_1584__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	vector<int> p;

	struct Edge {
		int len, u, v;
		Edge(int len, int u, int v) : len(len), u(u), v(v) {}
	};

	int minCostConnectPoints(vector<vector<int>> &points) {
		int n = points.size();
		p.resize(n, 0);

		for (int i = 0; i < p.size(); ++i) {
			p[i] = i;
		}

		vector<Edge> edges;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
				edges.emplace_back(dist, i, j);
			}
		}
		sort(edges.begin(), edges.end(), [](auto &x, auto &y) {
			return x.len < y.len;
		});

		int ans = 0;
		int num = 0;
		for (auto &[len, u, v]:edges) {
			if (!connected(u, v)) {
				ans += len;
				num++;
				if (num == n - 1) {
					break;
				}
			}
		}

		return ans;
	}

	int find(int i) {
		if (p[i] == i) return i;
		return p[i] = find(p[i]);
	}

	bool connected(int i, int j) {
		int pi = find(i), pj = find(j);
		if (pi == pj) {
			return true;
		}
		p[pi] = pj;
		return false;
	}
};

#endif //CPP_1584__SOLUTION1_H_

/**
 * @author ooooo
 * @date 2021/1/21 20:36 
 */

#ifndef CPP_1489__SOLUTION1_H_
#define CPP_1489__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
 public:

	struct UF {
		int n;
		vector<int> p;

		UF(int n) : n(n), p(n) {
			for (int i = 0; i < p.size(); ++i) {
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

		int size() {
			return n;
		}
	};


	vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
		vector<pair<int, vector<int>>> g;
		for (int i = 0; i < edges.size(); ++i) {
			g.emplace_back(i, edges[i]);
		}

		auto comp = [](auto &x, auto &y) {
			return x.second[2] < y.second[2];
		};
		sort(g.begin(), g.end(), comp);

		UF uf(n);
		// 计算最小生成树
		int minTotalWeight = 0;
		int count = 1;
		for (auto &[i, edge]: g) {
			int x = edge[0], y = edge[1], w = edge[2];
			if (!uf.connected(x, y)) {
				minTotalWeight += w;
				count++;
				if (count == n) {
					break;
				}
			}
		}

		vector<vector<int>> ans(2, vector<int>());
		for (int i = 0; i < edges.size(); ++i) {
			// 计算关键边
			int totalWeight = 0;
			count = 1;
			uf = UF(n);
			for (auto &[j, edge]: g) {
				// 不要i下标
				if (j == i) continue;
				int x = edge[0], y = edge[1], w = edge[2];
				if (!uf.connected(x, y)) {
					totalWeight += w;
					count++;
					if (count == n) break;
				}
			}

			if (uf.size() != 1 || totalWeight > minTotalWeight) {
				ans[0].push_back(i);
				continue;
			}

			// 计算伪关键边， 主要是看能不能组成最小生成树
			uf = UF(n);
			totalWeight = edges[i][2];
			uf.connected(edges[i][0], edges[i][1]);
			count = 1;
			for (auto &[j, edge]: g) {
				int x = edge[0], y = edge[1], w = edge[2];
				if (!uf.connected(x, y)) {
					totalWeight += w;
					count++;
					if (count == n) break;
				}
			}

			if (totalWeight == minTotalWeight) {
				ans[1].push_back(i);
			}
		}
		return ans;
	}

};

#endif //CPP_1489__SOLUTION1_H_

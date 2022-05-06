/**
 * @author ooooo
 * @date 2020/10/6 11:59 
 */

#ifndef CPP_0834__SOLUTION1_H_
#define CPP_0834__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

/**
 * bfs timeout
 */
class Solution {
 public:

	int bfs(vector<vector<int>> &g, int i) {
		vector<int> d(g.size(), 0);
		vector<int> visited(g.size(), false);
		queue<int> q;
		q.push(i);
		int ans = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			visited[u] = true;
			for (auto &v: g[u]) {
				if (visited[v]) continue;
				d[v] = d[u] + 1;
				q.push(v);
				ans += d[v];
			}
		}
		return ans;
	}

	vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
		vector<vector<int>> g(N);
		for (auto &e: edges) {
			int u = e[0], v = e[1];
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<int> ans;
		for (int i = 0; i < N; ++i) {
			ans.push_back(bfs(g, i));
		}
		return ans;
	}
};

#endif //CPP_0834__SOLUTION1_H_

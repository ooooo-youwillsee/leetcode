/**
 * @author ooooo
 * @date 2020/10/6 13:17 
 */

#ifndef CPP_0834__SOLUTION2_H_
#define CPP_0834__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
 public:

	// dp[i]：以i为根的距离总和
	// sz[i]: 以i为根的子节点大小（包括自身）
	vector<int> ans, dp, sz;
	vector<vector<int>> g;

	// 计算dp[0]
	void dfs(int u, int end) {
		dp[u] = 0; // 子节点到这个节点距离为0
		sz[u] = 1; // 包含自身
		for (auto &v: g[u]) {
			if (v == end) continue;
			dfs(v, u);
			sz[u] += sz[v];
			dp[u] += dp[v] + sz[v] * 1; // 每个节点共享一个
		}
	}

	// 以dp[0]推出其他节点
	void dfs2(int u, int end) {
		ans[u] = dp[u];
		for (auto &v : g[u]) {
			if (v == end) continue;
			int du = dp[u], dv = dp[v];
			int su = sz[u], sv = sz[v];

			dp[u] -= (dp[v] + sz[v]);
			sz[u] -= sz[v];
			dp[v] += (dp[u] + sz[u]);
			sz[v] += sz[u];

			dfs2(v, u);

			dp[u] = du;
			dp[v] = dv;
			sz[u] = su;
			sz[v] = sv;
		}
	}

	vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges) {
		g.resize(N, {});
		ans.resize(N, 0);
		dp.resize(N, 0);
		sz.resize(N, 0);
		for (auto &e: edges) {
			int u = e[0], v = e[1];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		// 传入-1 防止环
		dfs(0, -1);
		dfs2(0, -1);
		return ans;
	}
};

#endif //CPP_0834__SOLUTION2_H_

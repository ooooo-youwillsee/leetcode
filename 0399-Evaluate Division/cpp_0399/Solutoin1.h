/**
 * @author ooooo
 * @date 2021/1/6 09:33 
 */

#ifndef CPP_0399__SOLUTOIN1_H_
#define CPP_0399__SOLUTOIN1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
 public:

	// 图
	unordered_map<string, vector<string>> g;
	// 对应的权值
	unordered_map<string, vector<double>> vs;
	unordered_set<string> visited;

	double dfs(string u, string v, double y) {
		visited.insert(u);
		for (int j = 0; j < g[u].size(); ++j) {
			auto x = g[u][j];
			if (visited.count(x)) continue;
			if (x == v) {
				return y * vs[u][j];
			}
			double res = dfs(x, v, y * vs[u][j]);
			if (res != -1) {
				return res;
			}
		}
		return -1.0;
	}

	vector<double> calcEquation(vector<vector<string>> &equations,
															vector<double> &values,
															vector<vector<string>> &queries) {

		unordered_set<string> all;
		for (int i = 0; i < equations.size(); ++i) {
			string u = equations[i][0], v = equations[i][1];
			double uv = values[i], vv = 1 / values[i];
			g[u].push_back(v);
			g[v].push_back(u);
			vs[u].push_back(uv);
			vs[v].push_back(vv);
			all.insert(u);
			all.insert(v);
		}

		vector<double> ans(queries.size());
		for (int i = 0; i < queries.size(); ++i) {
			string u = queries[i][0], v = queries[i][1];
			// 不存在为-1
			if (!all.count(u) || !all.count(v)) {
				ans[i] = -1;
				continue;
			}
			// 相等为1
			if (u == v) {
				ans[i] = 1;
				continue;
			}
			visited.clear();
			ans[i] = dfs(u, v, 1.0);
		}
		return ans;
	}
};

#endif //CPP_0399__SOLUTOIN1_H_

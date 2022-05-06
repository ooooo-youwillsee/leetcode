/**
 * @author ooooo
 * @date 2020/10/11 10:29 
 */

#ifndef CPP_17_13__SOLUTION3_H_
#define CPP_17_13__SOLUTION3_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

class Solution {
 public:

	// 5535 https://leetcode-cn.com/contest/weekly-contest-210/problems/maximum-nesting-depth-of-the-parentheses/
	int maxDepth(string s) {
		stack<char> stack;
		int ans = 0;
		for (auto &c : s) {
			if (c == '(') {
				stack.push(c);
			} else if (c == ')') {
				ans = max(ans, (int) stack.size());
				stack.pop();
			}
		}
		return ans;
	}

	//5536 https://leetcode-cn.com/contest/weekly-contest-210/problems/maximal-network-rank/


	int maximalNetworkRank(int n, vector<vector<int>> &roads) {
		vector<vector<int>> g(n);
		for (auto &road: roads) {
			int u = road[0], v = road[1];
			g[u].push_back(v);
			g[v].push_back(u);
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				int sum = g[i].size() + g[j].size();
				for (auto &r: g[i]) {
					if (r == j) {
						sum--;
						break;
					}
				}
				ans = max(ans, sum);
			}
		}

		return ans;
	}

	// 5537 https://leetcode-cn.com/contest/weekly-contest-210/problems/split-two-strings-to-make-palindrome/

	bool help(string s) {
		int l = 0, r = s.size() - 1;
		while (l <= r) {
			if (s[l] == s[r]) {
				if (r == s.size() - 2 * l - 1) return true;
				l++;
				r--;
			} else {
				break;
			}
		}
		return false;
	}

	bool checkPalindromeFormation(string a, string b) {
		return a.size() <= 1 || help(a + b) || help(b + a);
	}

	//5538  https://leetcode-cn.com/contest/weekly-contest-210/problems/count-subtrees-with-max-distance-between-cities/

	set<pair<int, int>> ss;
	int bfs(int u, int n, int target) {
		int count = 0;
		queue<int> q;
		q.push(u);
		vector<int> paths(n + 1, 0);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			visited[x] = true;
			for (auto &v: g[x]) {
				if (visited[v]) continue;
				q.push(v);
				paths[v] = paths[x] + 1;
				if (paths[v] == target) {
					count++;
				}
			}
		}
		for (int i = 1; i < paths.size(); ++i) {
			if (paths[i] == target) {
				ss.insert({u, i});
				ss.insert({i, u});
			}
		}
		return count;
	}

	vector<vector<int>> g;
	vector<bool> visited;
	vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges) {
		g.assign(n + 1, {});

		int in_v = -1;
		for (auto &e: edges) {
			int u = e[0], v = e[1];
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<int> ans;

		for (int target = 1; target < n; ++target) {
			for (int u = 1; u <= n; ++u) {
				visited.assign(n + 1, false);
				bfs(u, n, target);
			}
			ans.push_back(ss.size());
			ss.clear();
		}
		return ans;
	}
};

#endif //CPP_17_13__SOLUTION3_H_

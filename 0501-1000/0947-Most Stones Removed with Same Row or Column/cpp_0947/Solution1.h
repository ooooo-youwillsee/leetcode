/**
 * @author ooooo
 * @date 2021/1/15 18:53 
 */

#ifndef CPP_0947__SOLUTION1_H_
#define CPP_0947__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	int ans = 0;

	void bfs(int rootIndex, unordered_set<int> &visited, unordered_map<int, vector<int>> &x,
					 unordered_map<int, vector<int>> &y, vector<vector<int>> &stones) {
		queue<int> q;
		q.push(rootIndex);
		while (!q.empty()) {
			auto i = q.front();
			q.pop();
			if (visited.count(i)) continue;
			ans++;
			visited.insert(i);
			// 取对应的x值
			for (auto &j:x[stones[i][0]]) {
				if (!visited.count(j)) q.push(j);
			}

			// 取对应的y值
			for (auto &j:y[stones[i][1]]) {
				if (!visited.count(j)) q.push(j);
			}
		}
		// 除去自己，自己不能删除
		ans--;
	}

	int removeStones(vector<vector<int>> &stones) {
		unordered_map<int, vector<int>> x, y;
		for (int i = 0; i < stones.size(); ++i) {
			x[stones[i][0]].push_back(i);
			y[stones[i][1]].push_back(i);
		}

		unordered_set<int> visited;
		for (int i = 0; i < stones.size(); ++i) {
			if (visited.count(i)) continue;
			bfs(i, visited, x, y, stones);
		}
		return ans;
	}
};

#endif //CPP_0947__SOLUTION1_H_

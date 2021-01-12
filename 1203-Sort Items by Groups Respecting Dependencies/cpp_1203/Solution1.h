/**
 * @author ooooo
 * @date 2021/1/12 13:17 
 */

#ifndef CPP_1203__SOLUTION1_H_
#define CPP_1203__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	vector<int> sortItems(int n, int m, vector<int> &groups, vector<vector<int>> &beforeItems) {
		// 对没有分组的项目，自己分组
		int curGroup = m;
		for (int i = 0; i < groups.size(); ++i) {
			if (groups[i] == -1) {
				groups[i] = curGroup;
				curGroup++;
			}
		}

		m = curGroup;
		vector<int> groupDegree(m), itemDegree(n);
		unordered_map<int, vector<int>> groupAdj, itemAdj;

		for (int i = 0; i < n; ++i) {
			for (auto &beforeItem: beforeItems[i]) {
				itemDegree[i]++;
				itemAdj[beforeItem].push_back(i);

				int beforeGroup = groups[beforeItem];
				int currentGroup = groups[i];
				if (beforeGroup != currentGroup) {
					groupAdj[beforeGroup].push_back(currentGroup);
					groupDegree[currentGroup]++;
				}
			}
		}

		vector<int> itemList = topologicalSort(itemDegree, itemAdj, n);
		if (itemList.empty()) {
			return {};
		}
		vector<int> groupList = topologicalSort(groupDegree, groupAdj, m);
		if (groupList.empty()) {
			return {};
		}

		unordered_map<int, vector<int>> groupMap;
		for (int i = 0; i < itemList.size(); ++i) {
			auto curItem = itemList[i];
			groupMap[groups[curItem]].push_back(curItem);
		}

		vector<int> ans;
		for (auto group: groupList) {
			ans.insert(ans.end(), groupMap[group].begin(), groupMap[group].end());
		}
		return ans;
	}

	vector<int> topologicalSort(vector<int> &degree, unordered_map<int, vector<int>> &adj, int n) {
		queue<int> q;
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			if (degree[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			auto item = q.front();
			ans.push_back(item);
			q.pop();
			for (auto otherItem: adj[item]) {
				degree[otherItem]--;
				if (degree[otherItem] == 0) {
					q.push(otherItem);
				}
			}
		}

		// 存在环就返回空
		if (ans.size() != n) {
			return {};
		}
		return ans;
	}
};

#endif //CPP_1203__SOLUTION1_H_

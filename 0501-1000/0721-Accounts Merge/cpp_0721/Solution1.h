/**
 * @author ooooo
 * @date 2021/1/18 17:13 
 */

#ifndef CPP_0721__SOLUTION1_H_
#define CPP_0721__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	unordered_map<string, int> email_index;
	vector<int> p;

	vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
		int count = 0;
		for (int i = 0; i < accounts.size(); ++i) {
			for (int j = 1; j < accounts[i].size(); ++j) {
				email_index[accounts[i][j]] = count;
				count++;
			}
		}

		p.assign(count, 0);
		for (int i = 0; i < p.size(); ++i) {
			p[i] = i;
		}

		for (int i = 0; i < accounts.size(); ++i) {
			string first = accounts[i][1];
			for (int j = 2; j < accounts[i].size(); ++j) {
				connected(email_index[first], email_index[accounts[i][j]]);
			}
		}

		unordered_map<int, pair<string, unordered_set<string>>> groups;
		for (int i = 0; i < accounts.size(); ++i) {
			for (int j = 1; j < accounts[i].size(); ++j) {
				int groupId = find(email_index[accounts[i][j]]);
				groups[groupId].first = accounts[i][0]; // name
				groups[groupId].second.insert(accounts[i][j]); // email
			}
		}

		vector<vector<string>> ans;
		for (auto &entry: groups) {
			string name = entry.second.first;
			ans.push_back({name});
			for (auto &email: entry.second.second) {
				ans.back().push_back(email);
			}
			sort(ans.back().begin(), ans.back().end());
		}
		return ans;
	}

	int find(int i) {
		if (p[i] == i) return i;
		return p[i] = find(p[i]);
	}

	bool connected(int i, int j) {
		int pi = find(p, i), pj = find(p, j);
		if (pi == pj) {
			return true;
		}
		p[pi] = pj;
		return false;
	}
};

#endif //CPP_0721__SOLUTION1_H_

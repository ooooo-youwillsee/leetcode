/**
 * @author ooooo
 * @date 2021/4/11 15:54 
 */

#ifndef CPP_1817__SOLUTION1_H_
#define CPP_1817__SOLUTION1_H_



#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
 public:

	vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
		unordered_map<int, unordered_set<int>> m;
		for (auto &log :logs) {
			m[log[0]].insert(log[1]);
		}

		unordered_map<int, int> x;
		for (auto &e : m) {
			x[e.second.size()]++;
		}

		vector<int> ans(k, 0);
		for (int i = 0; i < k; ++i) {
			ans[i] = x[i + 1];
		}
		return ans;
	}

};

#endif //CPP_1817__SOLUTION1_H_

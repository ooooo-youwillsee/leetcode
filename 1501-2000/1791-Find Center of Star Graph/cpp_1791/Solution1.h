/**
 * @author ooooo
 * @date 2021/3/28 12:11 
 */

#ifndef CPP_1791__SOLUTION1_H_
#define CPP_1791__SOLUTION1_H_

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

	int findCenter(vector<vector<int>> &edges) {
		unordered_map<int, int> m;
		for (auto &e: edges) {
			int u = e[0], v = e[1];
			m[u]++;
			m[v]++;
		}
		for (auto &e: m) {
			if (e.second == m.size() - 1) {
				return e.first;
			}
		}
		return false;
	}
};

#endif //CPP_1791__SOLUTION1_H_

/**
 * @author ooooo
 * @date 2021/1/15 19:27 
 */

#ifndef CPP_0947__SOLUTION2_H_
#define CPP_0947__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	int removeStones(vector<vector<int>> &stones) {
		vector<int> p(20002);
		for (int i = 0; i < p.size(); ++i) {
			p[i] = i;
		}
		for (int i = 0; i < stones.size(); ++i) {
			int x = stones[i][0], y = stones[i][1];
			connect(p, x + 10001, y)
		}

		unordered_set<int> set;
		for (auto &stone: stones) {
			set.insert(find(p, stone[0] + 10001));
		}
		return stones.size() - set.size();
	}

	int find(vector<int> &p, int i) {
		if (p[i] == i) return i;
		return p[i] = find(p, p[i]);
	}

	int connect(vector<int> &p, int i, int j) {
		int pi = find(p, i), pj = find(p, j);
		if (pi == pj) return pi;
		p[pi] = pj;
		return pj;
	}
};
#endif //CPP_0947__SOLUTION2_H_

/**
 * @author ooooo
 * @date 2021/4/30 19:57 
 */

#ifndef CPP_0403__SOLUTION1_H_
#define CPP_0403__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:

	/*
	 * i 表示第几个位置， step 表示上一步的步数
	 */
	bool dfs(int i, int step) {
		if (memo.find(i) != memo.end()) {
			if (memo[i].find(step) != memo[i].end()) {
				return memo[i][step];
			}
		}
		if (i == can.size()) return true;
		if (i > can.size()) return false;
		bool pass = false;
		if (i + step - 1 > i && can[i+step-1]) {
			pass = dfs(i + step - 1, step - 1);
		}

		if (i + step > i && can[i+step]) {
			pass = pass || dfs(i + step, step);
		}
		if (i + step + 1 > i && can[i+step+1]) {
			pass = pass || dfs(i + step + 1, step + 1);
		}
		return memo[i][step] = pass;
	}

	vector<bool> can;
	unordered_map<int, unordered_map<int, bool>> memo;

	bool canCross(vector<int>& stones) {
		can.assign(stones[stones.size() - 1], false);
		for (auto i: stones){
			can[i] = true;
		}
		if (!can[1]) return false;
		return dfs(1, 1);
	}
};

#endif //CPP_0403__SOLUTION1_H_

/**
 * @author ooooo
 * @date 2021/2/17 19:22 
 */

#ifndef CPP_0518__SOLUTION2_H_
#define CPP_0518__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int dfs(int amount, vector<int> &coins, int i) {
		if (visited[amount][i]) {
			return memo[amount][i];
		}
		if (amount == 0) {
			return 1;
		}

		int ans = 0;
		for (int j = i; j < coins.size(); ++j) {
			if (amount - coins[j] >= 0) {
				ans += dfs(amount - coins[j], coins, j);
			}
		}
		memo[amount][i] = ans;
		visited[amount][i] = true;
		return ans;
	}
	unordered_map<int, unordered_map<int, int>> memo;
	unordered_map<int, unordered_map<int, bool>> visited;

	int change(int amount, vector<int> &coins) {
		sort(coins.begin(), coins.end());
		memo.clear();
		visited.clear();
		return dfs(amount, coins, 0);
	}
};

#endif //CPP_0518__SOLUTION2_H_

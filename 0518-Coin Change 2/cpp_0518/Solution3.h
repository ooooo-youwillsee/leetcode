/**
 * @author ooooo
 * @date 2021/2/17 19:23 
 */

#ifndef CPP_0518__SOLUTION3_H_
#define CPP_0518__SOLUTION3_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int change(int amount, vector<int> &coins) {
		int n = coins.size();
		vector<int> dp(amount + 1, 0);
		// 没有任何金币，可以组合为0
		dp[0] = 1;
		for (auto coin : coins) {
			for (int i = 1; i <= amount; ++i) {
				if (i - coin >= 0) {
					dp[i] += dp[i - coin];
				}
			}
		}
		return dp[amount];
	}
};

#endif //CPP_0518__SOLUTION3_H_

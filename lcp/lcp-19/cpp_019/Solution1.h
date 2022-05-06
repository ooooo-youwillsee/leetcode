/**
 * @author ooooo
 * @date 2020/10/1 18:31 
 */

#ifndef CPP_019__SOLUTION1_H_
#define CPP_019__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:

	// 状态0 表示 最左边的为红色
	// 状态1 表示 中间的为黄色
	// 状态2 表示 最右边的为红色
	int minimumOperations(string leaves) {
		vector<vector<int>> dp(leaves.size(), vector<int>(3, 0));
		dp[0][0] = leaves[0] == 'y';
		dp[0][1] = dp[0][2] = dp[1][2] = leaves.size(); // 不可能存在

		for (int i = 1; i < leaves.size(); ++i) {
			int toRed = leaves[i] == 'y';
			int toYellow = leaves[i] == 'r';
			dp[i][0] = dp[i - 1][0] + toRed;
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + toYellow;
			if (i >= 2)
				dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + toRed;
		}
		return dp[leaves.size() - 1][2];
	}
};

#endif //CPP_019__SOLUTION1_H_

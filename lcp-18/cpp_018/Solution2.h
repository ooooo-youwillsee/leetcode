/**
 * @author ooooo
 * @date 2020/9/27 11:23 
 */

#ifndef CPP_018__SOLUTION2_H_
#define CPP_018__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int breakfastNumber(vector<int> &staple, vector<int> &drinks, int x) {
		vector<int> prices(x + 1, 0);
		int ans = 0;
		for (auto &item: staple) {
			if (item < x) prices[item]++;
		}

		// prices[i] 表示 小于i价格的个数
		for (int i = 2; i < x + 1; ++i) {
			prices[i] += prices[i - 1];
		}

		for (int i = 0; i < drinks.size(); ++i) {
			int y = x - drinks[i];
			if (y > 0) ans = (ans + prices[y]) % 1000000007;
		}

		return ans;
	}
};

#endif //CPP_018__SOLUTION2_H_

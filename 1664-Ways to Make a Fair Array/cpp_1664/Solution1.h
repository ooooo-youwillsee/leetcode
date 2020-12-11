/**
 * @author ooooo
 * @date 2020/12/11 10:31 
 */

#ifndef CPP_1664__SOLUTION1_H_
#define CPP_1664__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int waysToMakeFair(vector<int> &nums) {
		int n = nums.size();
		if (n == 1) return 1;
		vector<int> sum(n);
		sum[0] = nums[0];
		sum[1] = nums[1];
		for (int i = 2; i < n; ++i) {
			sum[i] = sum[i - 2] + nums[i];
		}
		int totalOdd, totalEven;
		if ((n - 1) % 2 == 0) {
			totalEven = sum[n - 1];
			totalOdd = sum[n - 2];
		} else {
			totalOdd = sum[n - 1];
			totalEven = sum[n - 2];
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int prevOdd, prevEven, remainOdd, remainEven;
			if (i % 2 == 0) {
				prevOdd = i >= 1 ? sum[i - 1] : 0, prevEven = i >= 2 ? sum[i - 2] : 0;
				remainOdd = totalEven - nums[i] - prevEven, remainEven = totalOdd - prevOdd;
			} else {
				prevOdd = i >= 2 ? sum[i - 2] : 0, prevEven = i >= 1 ? sum[i - 1] : 0;
				remainEven = totalOdd - nums[i] - prevOdd, remainOdd = totalEven - prevEven;
			}
			if (prevOdd + remainOdd == prevEven + remainEven) {
				ans += 1;
			}
		}
		return ans;
	}
};

#endif //CPP_1664__SOLUTION1_H_

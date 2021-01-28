/**
 * @author ooooo
 * @date 2021/1/28 20:34 
 */

#ifndef CPP_0724__SOLUTION1_H_
#define CPP_0724__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int pivotIndex(vector<int> &nums) {
		int n = nums.size();
		vector<int> sum(n + 1);
		for (int i = 0; i < n; ++i) {
			sum[i + 1] = sum[i] + nums[i];
		}
		for (int i = 0; i < n; ++i) {
			if (sum[i] == sum[n] - sum[i + 1]) {
				return i;
			}
		}
		return -1;
	}
};

#endif //CPP_0724__SOLUTION1_H_

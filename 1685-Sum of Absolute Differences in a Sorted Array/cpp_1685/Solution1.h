/**
 * @author ooooo
 * @date 2020/12/20 13:07 
 */

#ifndef CPP_1685__SOLUTION1_H_
#define CPP_1685__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <math.h>
using namespace std;

class Solution {
 public:

	vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
		int n = nums.size();
		vector<int> sum(n);
		sum[0] = nums[0];
		for (int i = 1; i < n; ++i) {
			sum[i] = sum[i - 1] + nums[i];
		}

		vector<int> ans(n, 0);
		for (int i = 0; i < n; ++i) {
			if (i > 0) {
				ans[i] += (i * nums[i] - sum[i - 1]);
			}
			if (i < n) {
				ans[i] += (sum[n - 1] - sum[i] - (n - 1 - i) * nums[i]);
			}
		}
		return ans;
	}
};

#endif //CPP_1685__SOLUTION1_H_

/**
 * @author ooooo
 * @date 2021/3/28 12:17 
 */

#ifndef CPP_1800__SOLUTION1_H_
#define CPP_1800__SOLUTION1_H_


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

	int maxAscendingSum(vector<int> &nums) {
		int ans = nums[0];
		int cur = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] > nums[i - 1]) {
				cur += nums[i];
			} else {
				ans = max(ans, cur);
				cur = nums[i];
				ans = max(ans, cur);
			}
		}
		ans = max(ans, cur);
		return ans;
	}
};

#endif //CPP_1800__SOLUTION1_H_

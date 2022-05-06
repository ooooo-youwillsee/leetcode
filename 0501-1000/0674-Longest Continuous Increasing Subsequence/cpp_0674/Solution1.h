/**
 * @author ooooo
 * @date 2021/1/24 09:19 
 */

#ifndef CPP_0674__SOLUTION1_H_
#define CPP_0674__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int findLengthOfLCIS(vector<int> &nums) {
		if (nums.empty()) return 0;
		int ans = 1, cur = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] > nums[i - 1]) {
				cur++;
			} else {
				cur = 1;
			}
			ans = max(ans, cur);
		}
		return ans;
	}
};

#endif //CPP_0674__SOLUTION1_H_

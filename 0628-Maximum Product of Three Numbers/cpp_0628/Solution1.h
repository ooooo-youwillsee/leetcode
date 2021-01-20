/**
 * @author ooooo
 * @date 2021/1/20 12:08 
 */

#ifndef CPP_0628__SOLUTION1_H_
#define CPP_0628__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int maximumProduct(vector<int> &nums) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
	}
};

#endif //CPP_0628__SOLUTION1_H_

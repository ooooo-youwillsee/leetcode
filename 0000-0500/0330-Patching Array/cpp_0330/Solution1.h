/**
 * @author ooooo
 * @date 2020/12/29 17:36 
 */

#ifndef CPP_0330__SOLUTION1_H_
#define CPP_0330__SOLUTION1_H_

#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
	int minPatches(vector<int> &nums, int n) {
		int patches = 0;
		long long x = 1;
		int length = nums.size(), index = 0;
		while (x <= n) {
			if (index < length && nums[index] <= x) {
				x += nums[index];
				index++;
			} else {
				x <<= 1;
				patches++;
			}
		}
		return patches;
	}
};

#endif //CPP_0330__SOLUTION1_H_

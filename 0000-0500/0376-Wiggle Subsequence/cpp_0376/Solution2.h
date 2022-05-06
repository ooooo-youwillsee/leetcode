/**
 * @author ooooo
 * @date 2020/12/12 13:53 
 */

#ifndef CPP_0376__SOLUTION2_H_
#define CPP_0376__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int wiggleMaxLength(vector<int> &nums) {
		int n = nums.size();
		if (n <= 1) return n;
		vector<int> up(n, 1), down(n, 1);
		for (int i = 1; i < n; ++i) {
			if (nums[i] > nums[i - 1]) {
				up[i] = max(up[i - 1], down[i - 1] + 1);
				down[i] = down[i - 1];
			} else if (nums[i] < nums[i - 1]) {
				down[i] = max(down[i - 1], up[i - 1] + 1);
				up[i] = up[i - 1];
			}else {
				up[i] = up[i - 1];
				down[i] = down[i - 1];
			}
		}
		return max(up[n - 1], down[n - 1]);
	}
};

#endif //CPP_0376__SOLUTION2_H_

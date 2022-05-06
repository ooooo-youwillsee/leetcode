/**
 * @author ooooo
 * @date 2021/5/28 11:13 
 */

#ifndef CPP_0477__SOLUTION1_H_
#define CPP_0477__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
	int totalHammingDistance(vector<int> &nums) {
		int ans = 0;
		int n = nums.size();
		for (int i = 0; i < 32; i++) {
			int cnt_1 = 0;
			for (int j = 0; j < n; j++) {
				cnt_1 += (nums[j] >> i & 1);
			}
			ans += (n - cnt_1) * cnt_1;
		}
		return ans;
	}
};
#endif //CPP_0477__SOLUTION1_H_

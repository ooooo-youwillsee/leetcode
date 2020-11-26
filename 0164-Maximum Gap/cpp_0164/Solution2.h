/**
 * @author ooooo
 * @date 2020/11/26 19:19 
 */

#ifndef CPP_0164__SOLUTION2_H_
#define CPP_0164__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int maximumGap(vector<int> &nums) {
		if (nums.size() < 2) return 0;
		int n = nums.size();
		vector<int> buf(n);
		int a = 1, max_v = *max_element(nums.begin(), nums.end());

		while (max_v >= a) {
			vector<int> cnt(10), t(10);
			for (int i = 0; i < n; ++i) {
				int d = (nums[i] / a) % 10;
				cnt[d]++;
			}
			for (int i = 1; i <= 9; ++i) {
				t[i] = t[i - 1] + cnt[i - 1];
			}
			for (int i = 0; i < n; ++i) {
				int d = (nums[i] / a) % 10;
				buf[t[d]] = nums[i];
				t[d]++;
			}
			copy(buf.begin(), buf.end(), nums.begin());
			a *= 10;
		}

		int diff = 0;
		for (int i = 1; i < n; ++i) {
			diff = max(diff, nums[i] - nums[i - 1]);
		}
		return diff;
	}
};

#endif //CPP_0164__SOLUTION2_H_

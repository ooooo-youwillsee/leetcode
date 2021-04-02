/**
 * @author ooooo
 * @date 2021/4/2 18:20 
 */

#ifndef CPP_17_12__SOLUTION2_H_
#define CPP_17_12__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int trap(vector<int> &height) {
		int n = height.size();
		vector<int> left(n, 0), right(n, 0);
		for (int i = 1; i < n - 1; i++) {
			left[i] = max(left[i - 1], height[i - 1]);
		}
		for (int i = n - 2; i > 0; i--) {
			right[i] = max(right[i + 1], height[i + 1]);
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			int h = min(left[i], right[i]);
			if (h > height[i]) {
				ans += h - height[i];
			}
		}
		return ans;
	}
};

#endif //CPP_17_12__SOLUTION2_H_

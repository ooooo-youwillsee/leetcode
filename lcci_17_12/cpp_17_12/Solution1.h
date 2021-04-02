/**
 * @author ooooo
 * @date 2021/4/2 18:20 
 */

#ifndef CPP_17_12__SOLUTION1_H_
#define CPP_17_12__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int trap(vector<int> &height) {
		int n = height.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int l = 0, r = 0;
			for (int j = i - 1; j >= 0; j--) {
				l = max(l, height[j]);
			}
			for (int j = i + 1; j < n; j++) {
				r = max(r, height[j]);
			}
			int h = min(l, r);
			if (h > height[i]) {
				ans += h - height[i];
			}
		}
		return ans;
	}
};

#endif //CPP_17_12__SOLUTION1_H_

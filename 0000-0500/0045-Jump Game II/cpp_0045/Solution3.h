/**
 * @author ooooo
 * @date 2021/6/4 20:38 
 */

#ifndef CPP_0045__SOLUTION3_H_
#define CPP_0045__SOLUTION3_H_

#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
	int jump(vector<int> &nums) {
		int n = nums.size();
		int ans = 0, end = 0, pos = 0;
		for (int i = 0; i < n - 1; i++) {
			pos = max(pos, i + nums[i]);
			if (i == end) {
				ans++;
				end = pos;
			}
		}
		return ans;
	}
};

#endif //CPP_0045__SOLUTION3_H_

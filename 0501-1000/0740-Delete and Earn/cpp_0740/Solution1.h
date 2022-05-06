/**
 * @author ooooo
 * @date 2021/5/5 09:19 
 */

#ifndef CPP_0740__SOLUTION1_H_
#define CPP_0740__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int deleteAndEarn(vector<int> &nums) {
		unordered_map<int, int> m;
		int maxV = *max_element(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]]++;
		}

		int first = 0 * m[0], second = 1 * m[1];
		int ans = max(first, second);
		for (int i = 2; i <= maxV; i++) {
			int tmp = second;
			second = max(second, first + i * m[i]);
			first = tmp;
			ans = max(first, second);
		}
		return ans;
	}
};
#endif //CPP_0740__SOLUTION1_H_

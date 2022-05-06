/**
 * @author ooooo
 * @date 2020/11/15 09:40 
 */

#ifndef CPP_1630__SOLUTION1_H_
#define CPP_1630__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	bool isArithmeticArray(vector<int> &nums) {
		if (nums.size() < 2) return false;
		sort(nums.begin(), nums.end());
		int diff = nums[1] - nums[0];
		for (int i = 2; i < nums.size(); ++i) {
			if (nums[i] - nums[i - 1] != diff) return false;
		}
		return true;
	}

	vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) {
		vector<bool> ans;
		for (int i = 0; i < l.size(); ++i) {
			int start = l[i], end = r[i];
			vector<int> arr;
			for (int j = 0; start <= end; ++j, ++start) {
				arr.push_back(nums[start]);
			}
			ans.push_back(isArithmeticArray(arr));
		}
		return ans;
	}
}

#endif //CPP_1630__SOLUTION1_H_

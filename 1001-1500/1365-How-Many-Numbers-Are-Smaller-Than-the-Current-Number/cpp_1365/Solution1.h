/**
 * @author ooooo
 * @date 2020/10/26 08:59 
 */

#ifndef CPP_1365__SOLUTION1_H_
#define CPP_1365__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
		vector<int> copy = nums;
		sort(copy.begin(), copy.end());
		vector<int> ans;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = lower_bound(copy.begin(), copy.end(), nums[i]);
			int count = it - copy.begin();
			ans.push_back(count);
		}
		return ans;
	}
};

#endif //CPP_1365__SOLUTION1_H_

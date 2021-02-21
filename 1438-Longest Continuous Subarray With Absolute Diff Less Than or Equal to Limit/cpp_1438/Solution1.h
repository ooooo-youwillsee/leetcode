/**
 * @author ooooo
 * @date 2021/2/21 08:46 
 */

#ifndef CPP_1438__SOLUTION1_H_
#define CPP_1438__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
 public:
	int longestSubarray(vector<int> &nums, int limit) {
		multiset<int> set;
		int l = 0, r = 0;
		int ans = 0;
		while (r < nums.size()) {
			set.insert(nums[r]);
			while (*set.rbegin() - *set.begin() > limit) {
				set.erase(set.find(nums[l]));
				l++;
			}
			r++;
			ans = max(ans, r - l);
		}
		return ans;
	}
};

#endif //CPP_1438__SOLUTION1_H_

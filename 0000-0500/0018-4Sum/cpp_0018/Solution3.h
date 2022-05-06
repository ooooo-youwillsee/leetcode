/**
 * @author ooooo
 * @date 2020/10/5 10:30 
 */

#ifndef CPP_0018__SOLUTION3_H_
#define CPP_0018__SOLUTION3_H_

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:

	struct vec_hash {

		size_t operator()(vector<int> __v) const {
			size_t x = 0;
			for (int i = 0; i < __v.size(); ++i) {
				x += hash<int>{}(__v[i]) * (i << i);
			}
			return x;
		}
	};

	vector<vector<int>> fourSum(vector<int> &nums, int target) {
		unordered_set<vector<int>, vec_hash> ans;
		sort(nums.begin(), nums.end());

		int n = nums.size();
		for (int i = 0; i < n - 3; ++i) {
			for (int j = i + 1; j < n - 2; ++j) {
				int l = j + 1, r = n - 1;
				while (l < r) {
					int sum = nums[i] + nums[j] + nums[l] + nums[r];
					if (sum == target) {
						ans.insert({nums[i], nums[j], nums[l], nums[r]});
						l++;
						r--;
					} else if (sum < target) {
						l++;
					} else {
						r--;
					}
				}
			}
		}

		return vector<vector<int>>(ans.begin(), ans.end());
	}
};

#endif //CPP_0018__SOLUTION3_H_

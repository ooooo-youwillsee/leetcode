/**
 * @author ooooo
 * @date 2020/12/4 20:18 
 */

#ifndef CPP_0659__SOLUTION1_H_
#define CPP_0659__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:


	bool isPossible1(vector<int> &nums) {
		vector<pair<int, int>> groups;
		groups.push_back({nums[0], nums[0]});
		vector<int> indexes;
		indexes.push_back(nums[0]);
		int n = nums.size();
		for (int i = 1; i < n; ++i) {
			int num = nums[i];
			bool added = false;
			auto it = upper_bound(indexes.begin(), indexes.end(), num - 1);
			int j = it - indexes.begin() - 1;
			if (j >= 0 && indexes[j] + 1 == num) {
				indexes[j] = num;
				groups[j].second = num;
				added = true;
			}
			if (!added) {
				groups.push_back({num, num});
				indexes.push_back(num);
			}
		}
		for (auto &group: groups) {
			if (group.second - group.first + 1 < 3) return false;
		}
		return true;
	}






	bool isPossible(vector<int> &nums) {
		vector<pair<int, int>> groups;
		groups.push_back({nums[0], nums[0]});
		vector<int> indexes;
		indexes.push_back(nums[0]);
		int n = nums.size();
		for (int i = 1; i < n; ++i) {
			int num = nums[i];
			bool added = false;
			auto it = upper_bound(groups.begin(),
														groups.end(),
														make_pair(num - 1, num - 1),
														[](pair<int, int> v1, pair<int, int> v2) {
															return v1.second < v2.second;
														});
			int j = it - groups.begin() - 1;
			if (j >= 0 && indexes[j] + 1 == num) {
				indexes[j] = num;
				groups[j].second = num;
				added = true;
			}
			if (!added) {
				groups.push_back({num, num});
				indexes.push_back(num);
			}
		}
		for (auto &group: groups) {
			if (group.second - group.first + 1 < 3) return false;
		}
		return true;
	}
};

#endif //CPP_0659__SOLUTION1_H_

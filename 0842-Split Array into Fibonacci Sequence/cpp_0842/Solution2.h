/**
 * @author ooooo
 * @date 2020/12/8 20:07 
 */

#ifndef CPP_0842__SOLUTION2_H_
#define CPP_0842__SOLUTION2_H_

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
 public:

	long max_v = (int) (pow(2, 31) - 1);

	bool dfs(vector<int> &nums, string &s, int i) {
		int n = s.size();
		if (i >= n && nums.size() >= 3) return true;
		long cur = 0;
		for (int j = i; j < n; ++j) {
			if (j > i && s[i] == '0') {
				break;
			}
			cur = cur * 10 + s[j] - '0';
			if (nums.size() >= 2) {
				long next_num = (long) nums[nums.size() - 1] + (long) nums[nums.size() - 2];
				if (next_num > max_v) break;
				if (cur < next_num) {
					continue;
				} else if (cur > next_num) {
					break;
				}
			}
			nums.push_back(cur);
			if (dfs(nums, s, j + 1)) return true;
			nums.pop_back();
		}
		return false;
	}

	vector<int> splitIntoFibonacci(string s) {
		vector<int> nums;
		dfs(nums, s, 0);
		return nums;
	}
};

#endif //CPP_0842__SOLUTION2_H_

/**
 * @author ooooo
 * @date 2021/4/22 17:12 
 */

#ifndef CPP_0363__SOLUTION1_H_
#define CPP_0363__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
 public:
	int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
		int m = matrix.size(), n = matrix[0].size();
		int ans = INT_MIN;
		for (int i = 0; i < m; i++) {
			vector<int> nums(n);
			for (int j = i; j >= 0; j--) {
				for (int p = 0; p < n; p++) {
					nums[p] += matrix[j][p];
				}
				int sum = 0;
				set<int> s;
				// 重要！！！， 前缀和
				s.insert(0);
				for (auto num: nums) {
					sum += num;
					auto it = s.lower_bound(sum - k);
					if (it != s.end()) {
						ans = max(ans, sum - *it);
					}
					s.insert(sum);
				}
			}
		}
		return ans;
	}
};
#endif //CPP_0363__SOLUTION1_H_

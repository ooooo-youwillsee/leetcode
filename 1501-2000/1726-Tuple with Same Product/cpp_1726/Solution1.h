/**
 * @author ooooo
 * @date 2021/1/24 17:07 
 */

#ifndef CPP_1726__SOLUTION1_H_
#define CPP_1726__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <set>

using namespace std;

class Solution {
 public:

	int tupleSameProduct(vector<int> &nums) {
		int ans = 0;
		int n = nums.size();

		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int x = nums[i] * nums[j];
				ans += m[x] * 4 * 2;
				m[x]++;
			}
		}
		return ans;
	}
};

#endif //CPP_1726__SOLUTION1_H_

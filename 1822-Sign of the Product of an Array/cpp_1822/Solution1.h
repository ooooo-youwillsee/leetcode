/**
 * @author ooooo
 * @date 2021/4/16 19:09 
 */

#ifndef CPP_1822__SOLUTION1_H_
#define CPP_1822__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
 public:
	int arraySign(vector<int> &nums) {
		int n = nums.size();
		int x = 1;
		for (int i = 0; i < n; i++) {
			if (nums[i] < 0) {
				x *= -1;
			} else if (nums[i] == 0) {
				return 0;
			}
		}
		if (x < 0) {
			return -1;
		} else if (x > 0) {
			return 1;
		}
		return 0;
	}
};

#endif //CPP_1822__SOLUTION1_H_

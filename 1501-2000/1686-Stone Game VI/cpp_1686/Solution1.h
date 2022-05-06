/**
 * @author ooooo
 * @date 2021/4/11 16:46 
 */

#ifndef CPP_1686__SOLUTION1_H_
#define CPP_1686__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues) {
		int n = aliceValues.size();
		vector<int> nums(n);
		for (int i = 0; i < n; i++) {
			nums[i] = i;
		}

		sort(nums.begin(), nums.end(), [&](const int x, const int y) {
			return aliceValues[x] + bobValues[x] > aliceValues[y] + bobValues[y];
		});

		int a = 0;
		for (int i = 0; i < n; i += 2) {
			a += aliceValues[nums[i]];
		}
		int b = 0;
		for (int i = 1; i < n; i += 2) {
			b += bobValues[nums[i]];
		}
		if (a > b) return 1;
		if (a == b) return 0;
		return -1;
	}
};

#endif //CPP_1686__SOLUTION1_H_

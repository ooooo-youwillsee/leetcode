/**
 * @author ooooo
 * @date 2021/5/22 11:15 
 */

#ifndef CPP_0810__SOLUTION1_H_
#define CPP_0810__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	bool xorGame(vector<int> &nums) {
		if (nums.size() % 2 == 0) {
			return true;
		}
		int ans = 0;
		for (auto num: nums) {
			ans ^= num;
		}
		return ans == 0; // Alice 第一手时，就能获胜
	}
};

#endif //CPP_0810__SOLUTION1_H_

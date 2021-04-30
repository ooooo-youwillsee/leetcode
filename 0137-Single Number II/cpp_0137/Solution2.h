/**
 * @author ooooo
 * @date 2021/4/30 22:47 
 */

#ifndef CPP_0137__SOLUTION2_H_
#define CPP_0137__SOLUTION2_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int singleNumber(vector<int> &nums) {
		vector<int> bits(32, 0);
		for (int i = 0; i < nums.size(); i++) {
			int num = nums[i];
			for (int j = 0; j < 32; j++) {
				bits[31 - j] += num & 1;
				num >>= 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < 32; i++) {
			int x = bits[i] % 3;
			if (x) {
				ans = ans | (1 << (31 - i));
			}
		}
		return ans;
	}
};
#endif //CPP_0137__SOLUTION2_H_

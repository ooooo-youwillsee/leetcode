/**
 * @author ooooo
 * @date 2021/4/6 11:19 
 */

#ifndef CPP_0080__SOLUTION1_H_
#define CPP_0080__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int removeDuplicates(vector<int> &nums) {
		int i = 0;
		for (auto num : nums) {
			if (i < 2 || num != nums[i - 2]) {
				nums[i++] = num;
			}
		}
		return i;
	}
};
#endif //CPP_0080__SOLUTION1_H_

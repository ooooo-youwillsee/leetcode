/**
 * @author ooooo
 * @date 2020/9/25 23:54 
 */

#ifndef CPP_0153__SOLUTION1_H_
#define CPP_0153__SOLUTION1_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
	int findMin(vector<int> &nums) {
		return *min_element(nums.begin(), nums.end());
	}
};

#endif //CPP_0153__SOLUTION1_H_

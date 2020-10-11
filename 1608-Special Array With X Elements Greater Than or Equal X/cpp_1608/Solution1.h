/**
 * @author ooooo
 * @date 2020/10/11 13:40 
 */

#ifndef CPP_1608__SOLUTION1_H_
#define CPP_1608__SOLUTION1_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int specialArray(vector<int> &nums) {
	sort(nums.begin(), nums.end());
	for (int i = 1; i <= nums.size(); ++i) {
		auto it = lower_bound(nums.begin(), nums.end(), i);
		int x = nums.end() - it;
		if (x == i) return x;
	}
	return -1;
}

#endif //CPP_1608__SOLUTION1_H_

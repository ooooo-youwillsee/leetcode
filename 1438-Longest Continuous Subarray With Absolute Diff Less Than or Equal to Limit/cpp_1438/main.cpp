#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;

	vector<int> nums = {8, 2, 4, 7};
	int limit = 4;
	cout << solution.longestSubarray(nums, limit) << endl;
	return 0;
}

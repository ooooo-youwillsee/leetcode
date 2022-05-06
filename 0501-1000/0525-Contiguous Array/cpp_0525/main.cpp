#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	vector<int> nums = {0, 1};
	auto cnt = solution.findMaxLength(nums);
	cout << cnt << endl;
	return 0;
}

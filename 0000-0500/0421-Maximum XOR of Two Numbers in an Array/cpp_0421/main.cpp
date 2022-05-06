#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	vector<int> nums = {3, 10, 5, 25, 2, 8};

	int ans = solution.findMaximumXOR(nums);
	cout << ans << endl;
	return 0;
}

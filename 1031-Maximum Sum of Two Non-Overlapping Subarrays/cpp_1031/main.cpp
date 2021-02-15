#include <iostream>
#include "SolutIon2.h"

int main() {
	Solution solution;
	vector<int> nums = {0, 6, 5, 2, 2, 5, 1, 9, 4};
	cout << solution.maxSumTwoNoOverlap(nums, 1, 2) << endl;
	return 0;
}

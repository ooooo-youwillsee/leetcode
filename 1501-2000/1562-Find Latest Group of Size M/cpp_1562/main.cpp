#include <iostream>
#include "Solution1.h"

void test(vector<int> nums, int m) {
	Solution solution;
	cout << solution.findLatestStep(nums, m) << endl;
}

int main() {

	test({1, 2}, 1);
	test({3, 1, 5, 4, 2}, 2);
	test({3, 5, 1, 2, 4}, 1);
	return 0;
}

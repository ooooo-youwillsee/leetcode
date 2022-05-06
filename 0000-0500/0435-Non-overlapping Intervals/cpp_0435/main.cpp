#include <iostream>
#include "Solution1.h"

void test(vector<vector<int>> nums) {
	Solution solution;
	cout << solution.eraseOverlapIntervals(nums) << endl;
}

int main() {
	test({{1, 2}, {2, 3}, {3, 4}, {1, 3}}); // 1
	test({{1, 2}, {1, 2}, {1, 2}}); // 2
	test({{1, 2}, {2, 3}}); // 0

	return 0;
}

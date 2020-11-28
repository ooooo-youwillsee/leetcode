#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
	Solution solution;
	auto i = solution.reversePairs(nums);
	cout << i << endl;
}
int main() {
	test({2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647});
	test({-5, -5}); // 1
	test({1, 3, 2, 3, 1}); // 2
	test({2, 4, 3, 5, 1}); // 3
	return 0;
}

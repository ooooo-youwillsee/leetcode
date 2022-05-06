#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
	Solution s;
	cout << s.isPossible(nums) << endl;
}

int main() {
	test({1, 2, 3, 3, 4, 4, 5, 5});
	test({1, 2, 3, 3, 4, 5});
	return 0;
}

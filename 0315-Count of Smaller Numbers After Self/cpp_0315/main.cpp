#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
	Solution solution;
	auto ans = solution.countSmaller(nums);
	for (auto &num : ans) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {

	test({5, 2, 6, 1});
	return 0;
}

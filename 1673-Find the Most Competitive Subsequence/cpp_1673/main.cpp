#include <iostream>
#include "Solution1.h"

void test(vector<int> nums, int k) {
	Solution solution;
	auto ans = solution.mostCompetitive(nums, k);
	for(auto num:ans) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {
	test({2, 4, 3, 3, 5, 4, 9, 6}, 4);
	return 0;
}

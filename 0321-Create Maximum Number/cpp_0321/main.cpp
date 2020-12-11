#include <iostream>
#include "Solution1.h"

void test(vector<int> nums1, vector<int> nums2, int k) {
	Solution s;
	auto x = s.maxNumber(nums1, nums2, k);
	for (auto i : x) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	test({6, 7, 5}, {4, 8, 1}, 3);
	test({6, 7}, {6, 0, 4}, 5);
	test({3, 4, 6, 5}, {9, 1, 2, 5, 8, 3}, 5);
	return 0;
}

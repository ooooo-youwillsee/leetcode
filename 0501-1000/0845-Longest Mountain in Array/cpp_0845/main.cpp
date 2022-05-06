#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	//vector<int> nums = {2, 1, 4, 7, 3, 2, 5};
	//vector<int> nums = {9,8,7,6,5,4,3,2,1,0};
	vector<int> nums = {1, 2, 0, 2, 0, 2};
	auto ans = solution.longestMountain(nums);
	cout << ans << endl;
	return 0;
}

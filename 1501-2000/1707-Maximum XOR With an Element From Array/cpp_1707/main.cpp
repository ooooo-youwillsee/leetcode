#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	vector<int> nums = {0, 1, 2, 3, 4};
	vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};
	vector<int> ans = solution.maximizeXor(nums, queries);
	for (auto x : ans)
		cout << x << endl;
	return 0;
}

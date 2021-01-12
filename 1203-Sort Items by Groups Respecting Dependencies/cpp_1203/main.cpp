#include <iostream>
#include "Solution1.h"

void test(int n, int m, vector<int> groups, vector<vector<int>> beforeItemsMap) {
	Solution solution;
	auto ans = solution.sortItems(n, m, groups, beforeItemsMap);
	for (auto item: ans) {
		cout << item << " ";
	}
	cout << endl;
}

int main() {
	test(8, 2, {-1, -1, 1, 0, 0, 1, 0, -1}, {{}, {6}, {5}, {6}, {3}, {}, {4}, {}});
	test(8, 2, {-1, -1, 1, 0, 0, 1, 0, -1}, {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}});
	return 0;
}

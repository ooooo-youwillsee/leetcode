#include <iostream>
#include "Solution1.h"

void test(vector<vector<int>> grids, vector<vector<int>> hits) {
	Solution solution;
	auto ans = solution.hitBricks(grids, hits);
	for (auto i :ans) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	test({{1, 0, 1}, {1, 1, 1}}, {{0, 0}, {0, 2}, {1, 1}}); // 0, 3, 0
	//test({{1, 0, 0, 0}, {1, 1, 1, 0}}, {{1, 0}}); // 2
	//test({{1}, {1}, {1}, {1}, {1}}, {{3, 0}, {4, 0}, {1, 0}, {2, 0}, {0, 0}}); //
	return 0;
}

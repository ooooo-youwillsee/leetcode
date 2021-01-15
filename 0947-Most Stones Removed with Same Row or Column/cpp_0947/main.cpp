#include <iostream>
#include "Solution1.h"

void test(vector<vector<int>> stones) {
	Solution solution;
	auto i = solution.removeStones(stones);
	cout << i << endl;
}

int main() {
	test({{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}});
	test({{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}});
	return 0;
}

#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	int n = 5;
	vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6}};
	auto ans = solution.findCriticalAndPseudoCriticalEdges(n, edges);

	return 0;
}

#include <iostream>
#include "Solution2.h"

int main() {
	Solution solution;

	int n = 4;
	vector<vector<int>> edges = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
	cout << solution.maxNumEdgesToRemove(n, edges) << endl;

	return 0;
}

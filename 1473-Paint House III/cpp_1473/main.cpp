#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	vector<int> houses = {0, 0, 0, 0, 0};
	vector<vector<int>> cost = {{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}};
	cout << solution.minCost(houses, cost, 5, 2, 3) << endl;
	return 0;
}

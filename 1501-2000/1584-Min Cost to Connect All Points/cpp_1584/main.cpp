#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
	//vector<vector<int>> points = {{0, 0}, {1, 1}, {1, 0}, {-1, 1}};
	cout << solution.minCostConnectPoints(points) << endl;
	return 0;
}

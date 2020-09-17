#include <iostream>
#include "Solution1.h"

int main() {

	Solution1 solution_1;
	auto vec = solution_1.findRedundantDirectedConnection({{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}});
	cout << vec[0] << " " << vec[1] << endl;
	return 0;
}

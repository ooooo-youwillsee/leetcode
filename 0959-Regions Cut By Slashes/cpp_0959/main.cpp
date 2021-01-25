#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	vector<string> grid = {"//", "/ "};
	cout << solution.regionsBySlashes(grid) << endl;
	return 0;
}

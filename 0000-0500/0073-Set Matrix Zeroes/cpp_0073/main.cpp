#include <iostream>
#include "Solution2.h"

int main() {
	Solution solution;
	vector<vector<int>> matrix = {
		{1, 1, 1},
		{1, 0, 1},
		{1, 1, 1}
	};
	solution.setZeroes(matrix);
	return 0;
}

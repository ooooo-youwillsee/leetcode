#include <iostream>
#include "Solution1.h"

void test(vector<vector<int>> matrix) {
	Solution s;
	int ans = s.matrixScore(matrix);
	cout << ans << endl;
}

int main() {
	test({
				 {0, 0, 1, 1},
				 {1, 0, 1, 0},
				 {1, 1, 0, 0}
			 });
	return 0;
}

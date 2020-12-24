#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> ratings) {
	Solution solution;
	cout << solution.candy(ratings) << endl;
}

int main() {
	test({1, 3, 2, 1}); // 7
	test({1, 2, 3, 1}); // 7
	test({1, 0, 2}); // 5
	test({1, 2, 2}); // 4
	return 0;
}

#include <iostream>
#include "Solution1.h"

void test(vector<int> prices, int k) {
	Solution solution;
	cout << solution.maxProfit(k, prices) << endl;
}

int main() {
	test({2, 4, 1}, 2); // 2
	test({3, 2, 6, 5, 0, 3}, 2); // 7
	return 0;
}

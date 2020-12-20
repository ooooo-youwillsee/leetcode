#include <iostream>
#include "Solution1.h"

void test(vector<int> prices, int fee) {
	Solution solution;
	cout << solution.maxProfit(prices, fee) << endl;
}

int main() {
	test({1, 3, 2, 8, 4, 9}, 2);
	return 0;
}

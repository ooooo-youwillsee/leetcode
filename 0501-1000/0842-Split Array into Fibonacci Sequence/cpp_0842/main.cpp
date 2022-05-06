#include <iostream>
#include "Solution1.h"

void test(string s) {
	Solution solution;
	auto ans = solution.splitIntoFibonacci(s);
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	test("214748364721474836422147483641");
	test("112358130");
	test("11235813");
	test("123456579");
	return 0;
}

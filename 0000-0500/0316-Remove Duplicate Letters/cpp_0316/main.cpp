#include <iostream>
#include "Solution1.h"

void test(string s) {
	Solution solution;
	cout << solution.removeDuplicateLetters(s) << endl;
}

int main() {
	test("cbacdcbc");
	test("bcabc");
	return 0;
}

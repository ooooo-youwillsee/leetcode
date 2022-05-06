#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	cout << solution.removeKdigits("1234567890", 9) << endl;
	cout << solution.removeKdigits("1432219", 3) << endl;
	return 0;
}

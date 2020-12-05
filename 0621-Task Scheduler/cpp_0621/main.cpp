#include <iostream>
#include "Solution1.h"

void test(vector<char> tasks, int n) {
	Solution solution;
	auto cnt = solution.leastInterval(tasks, n);
	cout << cnt << endl;
}

int main() {
	test({'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}, 2); // 16
	test({'A', 'A', 'A', 'B', 'B', 'B'}, 2); // 8
	return 0;
}

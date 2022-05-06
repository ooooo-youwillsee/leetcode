#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	auto ans = solution.constructDistancedSequence(5);
	for (auto &i: ans) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}

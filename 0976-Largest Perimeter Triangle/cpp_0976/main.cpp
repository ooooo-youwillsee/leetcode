#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	vector<int> A3 = {2, 6, 2, 5, 4, 15, 1};
	cout << solution.largestPerimeter(A3) << endl;
	vector<int> A1 = {2, 1, 2};
	cout << solution.largestPerimeter(A1) << endl;
	vector<int> A2 = {3, 6, 2, 3};
	cout << solution.largestPerimeter(A2) << endl;

	return 0;
}

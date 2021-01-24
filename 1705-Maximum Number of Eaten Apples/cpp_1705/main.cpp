#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	vector<int> apples = {1, 2, 3, 5, 2};
	vector<int> days = {3, 2, 1, 4, 2};
	cout << solution.eatenApples(apples, days) << endl;
	return 0;
}

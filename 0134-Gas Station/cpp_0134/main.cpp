#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;

	vector<int> gas2 = {2, 3, 4}, cost2 = {3, 4, 3};
	cout << solution.canCompleteCircuit(gas2, cost2) << endl;

	vector<int> gas1 = {1, 2, 3, 4, 5}, cost1 = {3, 4, 5, 1, 2};
	cout << solution.canCompleteCircuit(gas1, cost1) << endl;

	return 0;
}

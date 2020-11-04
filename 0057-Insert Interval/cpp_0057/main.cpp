#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	vector<vector<int>> intervals = {{1, 3}, {6, 9}};
	vector<int> newInterval = {2, 5};
	auto ans = solution.insert(intervals, newInterval);
	for (auto &item: ans) {
		cout << item[0] << " " << item[1] << endl;
	}
	return 0;
}

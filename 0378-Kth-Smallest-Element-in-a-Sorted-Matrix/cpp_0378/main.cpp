#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	//vector<vector<int>> matrix = {
	//	{1, 5, 9},
	//	{10, 11, 13},
	//	{12, 13, 15}
	//};
	//int k = 8;

	vector<vector<int>> matrix = {
		{1, 3, 5},
		{6, 7, 12},
		{11, 14, 14}
	};
	int k = 5;

	cout << solution.kthSmallest(matrix, k) << endl;
	return 0;
}

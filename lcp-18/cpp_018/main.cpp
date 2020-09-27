#include <iostream>
#include "Solution1.h"

using namespace std;

int main() {
	//vector<int> vec = {1, 4, 5, 6, 6, 7, 10};
	//int x = upper_bound(vec.begin(), vec.end(), 11) - vec.begin();
	//cout<< x << endl;
	vector<int> vec1 = {10,20,5}, vec2 = {5,5,2};
	Solution solution;
	auto i = solution.breakfastNumber(vec1, vec2, 15);
	cout << i << endl;

	return 0;
}

#include <iostream>
#include "Solutoin1.h"

void test(vector<vector<string>> &equations,
					vector<double> &values,
					vector<vector<string>> &queries) {
	Solution solution;
	auto ans = solution.calcEquation(equations, values, queries);
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
	vector<double> values = {2.0, 3.0};
	vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
	test(equations, values, queries);
	return 0;
}

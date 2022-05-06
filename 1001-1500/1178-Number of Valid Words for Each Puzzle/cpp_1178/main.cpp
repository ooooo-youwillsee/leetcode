#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	vector<string> words = {"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
	vector<string> puzzles = {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};
	auto ans = solution.findNumOfValidWords(words, puzzles);
	for (auto item: ans) {
		cout << item << " ";
	}
	cout << endl;
	return 0;
}

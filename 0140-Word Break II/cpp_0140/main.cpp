#include <iostream>
#include "Solution1.h"

int main() {

	Solution solution;
	vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
	string s = "catsanddog";
	auto ans = solution.wordBreak(s, wordDict);
	for (auto &item :ans) {
		cout << item << endl;
	}
	return 0;
}

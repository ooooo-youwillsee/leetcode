#include <iostream>
#include "Solution1.h"

int main() {
	Solution solution;
	//vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
	//int maxWidth = 16;
	//vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
	//int maxWidth = 20;
	vector<string> words = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
	int maxWidth = 16;
	auto ans = solution.fullJustify(words, maxWidth);
	for (auto &line : ans) {
		cout << line << endl;
	}
	cout << endl;
	return 0;
}

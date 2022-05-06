#include <iostream>
#include "Solution2.h"

int main() {
	vector<string> dict = {"xyzu"};
	string sentence = "xyzu";
	Solution solution;
	int i = solution.respace(dict, sentence);
	cout << i << endl;
	return 0;
}

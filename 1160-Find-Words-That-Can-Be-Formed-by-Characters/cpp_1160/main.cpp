#include <iostream>
#include "Solution1.h"

void test(vector<string> words, string chars) {
  Solution solution;
  cout << solution.countCharacters(words, chars) << endl;
}

int main() {
  test({"cat", "bt", "hat", "tree"}, "atach");  // 6
  test({"hello", "world", "leetcode"}, "welldonehoneyr"); // 10
  return 0;
}

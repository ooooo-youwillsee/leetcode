#include <iostream>
#include "Solution1.h"

void test(vector<string> strs) {
  Solution solution;
  cout << solution.longestCommonPrefix(strs) << endl;
}

int main() {
  test({"flower", "flow", "flight"}); // "fl"
  test({"dog", "racecar", "car"}); // ""
  return 0;
}

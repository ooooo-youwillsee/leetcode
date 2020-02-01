#include <iostream>
#include "Solution1.h"

void test(vector<string> vec) {
  Solution solution;
  cout << solution.numSpecialEquivGroups(vec) << endl;
}

int main() {
  test({"a", "b", "c", "a", "c", "c"});
  test({"aa", "bb", "ab", "ba"});
  test({"abc", "acb", "bac", "bca", "cab", "cba"});
  test({"abcd", "cdab", "adcb", "cbad"});
  return 0;
}
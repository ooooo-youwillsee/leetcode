#include <iostream>
#include "Solution1.h"

void test(string s, int k) {
  Solution solution;
  cout << solution.reverseStr(s, k) << endl;
}

int main() {
  test("abcdefg", 2); // "bacdfeg"
  test("a", 2);  // "a"
  return 0;
}

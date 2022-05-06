#include <iostream>
#include "Solution1.h"

void test(string a, string b) {
  Solution solution;
  cout << solution.findLUSlength(a, b) << endl;
}

int main() {
  test("aba", "abc");
  return 0;
}

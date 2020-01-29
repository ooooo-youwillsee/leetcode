#include <iostream>
#include "Solution1.h"
#include <sstream>

void test(string A, string B) {
  Solution solution;
  cout << solution.repeatedStringMatch(A, B) << endl;
}

int main() {
  test("abcd", "cdabcdab");
  test("aaaaaaaaaaaaaaaaaaaaaab", "ba");
  return 0;
}

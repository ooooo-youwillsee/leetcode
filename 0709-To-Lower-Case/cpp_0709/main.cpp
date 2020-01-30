#include <iostream>
#include "Solution1.h"

void test(string s) {
  Solution solution;
  cout << solution.toLowerCase(s) << endl;
}

int main() {
  test("Hello");
  test("here");
  test("LOVELY");
  return 0;
}

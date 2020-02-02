#include <iostream>
#include "Solution1.h"

void test(string s) {
  Solution solution;
  cout << solution.defangIPaddr(s) << endl;
}

int main() {
  test("1.1.1.1");
  test("255.100.50.0");
  return 0;
}

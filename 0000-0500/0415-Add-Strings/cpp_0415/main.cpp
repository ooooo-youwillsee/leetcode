#include <iostream>
#include "Solution1.h"

void test(string num1, string num2) {
  Solution solution;
  cout << solution.addStrings(num1, num2) << endl;
}

int main() {
  test("11", "99"); // 110
  return 0;
}

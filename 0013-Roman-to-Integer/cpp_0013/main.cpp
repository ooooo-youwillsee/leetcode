#include <iostream>
#include "Solution1.h"

void test(string s) {
  Solution solution;
  cout << solution.romanToInt(s) << endl;
}

int main() {
  test("III"); // 3
  test("IV"); // 4
  test("IX"); // 9
  test("LVIII"); // 58
  test("MCMXCIV"); // 1994
  return 0;
}

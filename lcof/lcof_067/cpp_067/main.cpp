#include <iostream>
#include "Solution1.h"

void test(string str) {
  Solution solution;
  cout << solution.strToInt(str) << endl;
}

int main() {
  cout << INT_MAX << endl;
  test("20000000000000000000"); // 2147483647
  test("-91283472332");  // -2147483648
  test("42"); // 42
  test("   -42"); //
  test("4193 with words"); //4193-42
  test("words and 987"); // 0
  return 0;
}

#include <iostream>
#include "Solution1.h"

void test(string s) {
  Solution solution;
  cout << solution.countSegments(s) << endl;
}

int main() {
  test("Hello, my name is John"); // 5
  test(" "); // 0
  test(""); // 0
  return 0;
}

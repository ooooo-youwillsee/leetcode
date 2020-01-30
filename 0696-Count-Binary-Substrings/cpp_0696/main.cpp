#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s) {
  Solution solution;
  cout << solution.countBinarySubstrings(s) << endl;
}

int main() {
  test("00110011"); // 6
  test("10101"); // 4
  test("00110"); // 3
  return 0;
}

#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s) {
  Solution solution;
  cout << solution.lengthOfLastWord(s) << endl;
}

int main() {
  test("Hello World");  // 5
  test("a"); // 1
  test("a "); // 1
  test("a c"); // 1
  test("a  c"); // 1
  test("ac"); // 2
  return 0;
}

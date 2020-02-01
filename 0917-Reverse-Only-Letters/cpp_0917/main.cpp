#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s) {
  Solution solution;
  cout << solution.reverseOnlyLetters(s) << endl;
}

int main() {
  test("ab-cd");
  test("a-bC-dEf-ghIj");
  test("Test1ng-Leet=code-Q!");
  return 0;
}

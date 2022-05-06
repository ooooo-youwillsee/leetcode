#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s1, string s2) {
  Solution solution;
  cout << solution.canConstruct(s1, s2) << endl;
}

int main() {
  test("a", "b"); // 0
  test("aa", "ab"); // 0
  test("aa", "aab"); // 1
  return 0;
}

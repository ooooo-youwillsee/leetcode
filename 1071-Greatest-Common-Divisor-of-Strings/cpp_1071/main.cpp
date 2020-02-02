#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string str1, string str2) {
  Solution solution;
  cout << solution.gcdOfStrings(str1, str2) << endl;
}

int main() {
  test("ABCABC", "ABC"); // "ABC"
  test("ABABAB", "ABAB"); // "AB"
  test("LEET", "CODE"); // ""
  test("ABCDEF", "ABC"); // ""
  return 0;
}

#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s) {
  Solution solution;
  cout << solution.validPalindrome(s) << endl;
}

int main() {
  test("aba");   // 1
  test("abca");  // 1
  return 0;
}

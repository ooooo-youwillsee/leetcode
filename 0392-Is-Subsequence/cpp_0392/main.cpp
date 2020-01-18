#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string s, string t) {
  Solution solution;
  cout << solution.isSubsequence(s, t) << endl;
}

int main() {
  test("abc", "ahbgdc"); // 1
  test("axc", "ahbgdc"); // 0
  return 0;
}

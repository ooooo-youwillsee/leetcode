#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(string s, string t) {
  Solution solution;
  cout << solution.findTheDifference(s, t) << endl;
}

int main() {
  test("abcd", "abcde");
  test("abcd", "abcdb");
  return 0;
}

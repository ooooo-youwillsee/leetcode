#include <iostream>
#include "Solution1.h"

void test(string s) {
  Solution solution;
  cout << solution.firstUniqChar(s) << endl;
}

int main() {
  test("abaccdeff");
  test("");
  return 0;
}

#include <iostream>
#include "Solution1.h"
//#include "Solution2.h"

void test(string s) {
  Solution solution;
  auto ans = solution.permutation(s);
  for (auto &str: ans) cout << str << " ";
  cout << endl;
}

int main() {
  test("abc");
  test("aab");
  return 0;
}

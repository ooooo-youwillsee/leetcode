#include <iostream>
#include "Solution1.h"

void test(vector<string> ss) {
  Solution solution;
  for (auto &s: ss)
    cout << solution.isNumber(s) << " ";
  cout << endl;
}

int main() {
  test({"1 ", "+100", "5e2", "-123", "3.1416", "0123", "-1E-16"}); // 1
  test({"12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"}); // 0
  return 0;
}

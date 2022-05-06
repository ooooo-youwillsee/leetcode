#include <iostream>
#include "Solution1.h"

void test(int n) {
  Solution solution;
  auto ans = solution.printNumbers(n);
  for (auto &num: ans) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  test(2);
  return 0;
}

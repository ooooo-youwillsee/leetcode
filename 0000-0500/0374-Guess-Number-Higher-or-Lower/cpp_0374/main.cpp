#include <iostream>
#include "Solution1.h"

void test(int n) {
  Solution solution;
  cout << solution.guessNumber(n) << endl;
}

int main() {
  test(10);
  test(6);
  test(7);
  test(8);
  test(9);
  return 0;
}

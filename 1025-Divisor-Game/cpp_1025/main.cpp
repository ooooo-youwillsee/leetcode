#include <iostream>
#include "Solution1.h"

void test(int N) {
  Solution solution;
  cout << solution.divisorGame(N) << endl;
}

int main() {
  test(2); // 1
  test(3); // 0
  return 0;
}

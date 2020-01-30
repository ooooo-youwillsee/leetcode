#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(int N) {
  Solution solution;
  cout << solution.rotatedDigits(N) << endl;
}

int main() {
  test(10);
  return 0;
}

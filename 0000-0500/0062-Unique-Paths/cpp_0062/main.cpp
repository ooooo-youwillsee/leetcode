#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(int m, int n) {
  Solution solution;
  cout << solution.uniquePaths(m, n) << endl;
}

int main() {
  test(3, 2); // 3
  test(7, 3); // 28
  return 0;
}

#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
//#include "Solution3.h"
#include "Solution4.h"

void test(int n) {
  Solution solution;
  cout << solution.numSquares(n) << endl;
}

int main() {
  test(49); // 1
  test(12); // 3
  test(13); // 2
  test(6255); // 4
  return 0;
}

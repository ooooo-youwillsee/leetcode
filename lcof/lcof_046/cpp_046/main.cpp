#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(int num) {
  Solution solution;
  cout << solution.translateNum(num) << endl;
}

int main() {
  test(26); // 1
  test(18580); // 2
  test(25); // 2
  test(12258); // 5
  return 0;
}

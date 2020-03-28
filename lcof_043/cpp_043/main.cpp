#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(int n) {
  Solution solution;
  cout << solution.countDigitOne(n) << endl;
}

int main() {
  test(10); // 2
  test(12); // 5
  test(13); // 6
  return 0;
}

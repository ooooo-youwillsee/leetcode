#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(int x, int y) {
  Solution solution;
  cout << solution.hammingDistance(x, y) << endl;
}

int main() {
  test(1, 4); // 2
  return 0;
}

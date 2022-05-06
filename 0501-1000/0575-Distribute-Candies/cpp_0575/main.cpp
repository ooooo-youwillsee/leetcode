#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> vec) {
  Solution solution;
  cout << solution.distributeCandies(vec) << endl;
}

int main() {
  test({1, 1, 2, 2, 3, 3}); // 3
  test({1, 1, 2, 2, 3, 3, 4, 5}); // 4
  test({1, 1, 2, 3}); // 2
  test({1, 1, 1, 1, 2, 2, 2, 3, 3, 3}); // 3
  return 0;
}

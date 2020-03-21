#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> postOrders) {
  Solution solution;
  cout << solution.verifyPostorder(postOrders) << endl;
}

int main() {
  test({3, 10, 6, 9, 2}); // 0
  test({5, 4, 3, 2, 1}); // 1
  test({1, 6, 3, 2, 5}); // 0
  test({1, 3, 2, 6, 5}); // 1
  test({4, 6, 12, 8, 16, 14, 10}); // 0
  return 0;
}

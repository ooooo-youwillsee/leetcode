#include <iostream>
#include "Solution1.h"

void test(vector<int> prices) {
  Solution solution;
  cout << solution.maxProfit(prices) << endl;
}

int main() {
  test({1}); // 0
  test({}); // 0
  test({1, 2, 3, 0, 2}); // 3
  test({1, 2, 3, 4}); // 3
  return 0;
}

#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(vector<int> coins, int amount) {
  Solution solution;
  cout << solution.coinChange(coins, amount) << endl;
}

int main() {
  test({2}, 3);  // -1
  test({1, 2, 5}, 11);  // 3
  return 0;
}

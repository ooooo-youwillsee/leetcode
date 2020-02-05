#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> prices) {
  Solution solution;
  cout << solution.maxProfit(prices) << endl;
}

int main() {
  test({7, 1, 5, 3, 6, 4});
  test({7, 6, 4, 3, 1});
  return 0;
}

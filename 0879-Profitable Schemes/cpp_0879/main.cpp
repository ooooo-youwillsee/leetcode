#include <iostream>
#include "Solution1.h"

int main() {
  int n = 5, minProfit = 3;
  vector<int> group = {2, 2}, profit = {2, 3};
  Solution solution;
  auto ans = solution.profitableSchemes(n, minProfit, group, profit);
  cout << ans << endl;
  return 0;
}

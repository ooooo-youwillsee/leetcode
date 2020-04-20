#include <iostream>
#include "Solution1.h"

void test(int n) {
  Solution solution;
  auto ans = solution.twoSum(n);
  for (auto &item: ans) cout << item << " ";
  cout << endl;
}

int main() {
  test(2);
  test(1);
  return 0;
}

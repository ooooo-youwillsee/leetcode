#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> vec) {
  Solution solution;
  cout << solution.findLHS(vec) << endl;
}

int main() {
  test({1, 3, 2, 2, 5, 2, 3, 7});  // 5
  test({1, 1, 1, 1}); // 0
  return 0;
}

#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"
//#include "Solution3.h"

void test(vector<int> nums) {
  Solution solution;
  for (auto &n:nums)
    cout << solution.fib(n) << endl;
}

int main() {
  test({0, 1, 2, 5, 95, 100});
  return 0;
}

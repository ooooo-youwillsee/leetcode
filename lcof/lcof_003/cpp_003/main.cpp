#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.findRepeatNumber(nums) << endl;
}

int main() {
  test({2, 3, 1, 0, 2, 5, 3}); // 2 or 3
  return 0;
}

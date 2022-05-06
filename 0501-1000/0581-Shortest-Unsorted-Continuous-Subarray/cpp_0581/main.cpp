#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
  Solution solution;
  cout << solution.findUnsortedSubarray(nums) << endl;
}

int main() {
  test({2}); // 0
  test({2, 3}); // 0
  test({2, 6, 4, 8, 10, 9, 15}); // 5
  return 0;
}

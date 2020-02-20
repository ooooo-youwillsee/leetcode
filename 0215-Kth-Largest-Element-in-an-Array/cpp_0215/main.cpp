#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums, int k) {
  Solution solution;
  cout << solution.findKthLargest(nums, k) << endl;
}

int main() {
  test({3, 2, 1, 5, 6, 4}, 2); // 5
  test({3, 2, 3, 1, 2, 4, 5, 5, 6}, 4); // 4
  return 0;
}

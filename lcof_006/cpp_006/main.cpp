#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(vector<int> nums) {
  Solution solution;
  auto ans = solution.reversePrint(new ListNode(nums));
  for (auto &num: ans) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  test({1, 3, 2});
  return 0;
}

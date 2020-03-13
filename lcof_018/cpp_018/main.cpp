#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

void test(vector<int> nums, int del_val) {
  Solution solution;
  auto ans = solution.deleteNode(new ListNode(nums), del_val);
  while (ans) {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
}

int main() {
  test({1, 2, 3}, 1);
  test({1, 2, 3}, 0);
  return 0;
}

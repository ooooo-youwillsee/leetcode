#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
  Solution solution;
  ListNode *ans = solution.sortList(new ListNode(nums));
  while (ans) {
    cout << ans->val << " ";
    ans = ans->next;
  }
  cout << endl;
}

int main() {
  test({4, 2, 1, 3});
  return 0;
}

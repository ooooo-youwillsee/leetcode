#include <iostream>
#include "Solution1.h"

void test(int target) {
  Solution solution;
  auto ans = solution.findContinuousSequence(target);
  for (auto &group: ans) {
    for (auto &num: group) cout << num << " ";
    cout << endl;
  }
  cout << endl;
}

int main() {
  test(9);
  test(15);
  return 0;
}

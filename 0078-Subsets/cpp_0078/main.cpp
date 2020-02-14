#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
  Solution solution;
  auto ans = solution.subsets(nums);
  for (auto group: ans) {
    for (auto item: group) {
      cout << item << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  test({1, 2, 3});
  return 0;
}

#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
  Solution solution;
  solution.sortColors(nums);
  for (auto &num: nums) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {

  test({0, 0, 1, 0, 1, 1});
  test({2, 0, 2});
  test({2, 0, 2, 1, 1, 0});
  test({2, 0, 0});
  test({0, 1, 0});
  test({0, 0, 0});
  test({2, 2, 2});
  test({0, 0});
  return 0;
}

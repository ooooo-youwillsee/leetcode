#include <iostream>
#include "Solution1.h"

void test(vector<int> nums) {
  Solution solution;
  solution.nextPermutation(nums);
  for (auto &item: nums) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  test({1, 2, 3}); // 1 3 2
  test({1, 3, 2}); // 2 1 3
  test({2, 5, 3, 3}); // 3 2 3 5
  test({3, 2, 1}); //  1 2 3
  test({2, 3, 2, 1}); // 3 1 2 2
  test({1, 1, 5}); // 1 5 1
  test({1, 5, 1}); // 5 1 1
  return 0;
}

#include <iostream>
#include "Solution1.h"

int main() {
  //vector<int> nums = {1, 3, 5};
  vector<int> nums = {};
  NumArray num_array = nums;
  cout << num_array.sumRange(0, 2) << endl;
  num_array.update(1, 2);
  cout << num_array.sumRange(0, 2) << endl;
  return 0;
}

#include <iostream>
#include "Solution1.h"

void test(vector<string> nums) {
  Codec codec;
  auto str = codec.serialize(new TreeNode(nums));
  cout << str << endl;
  auto node = codec.deserialize(str);
  cout << endl;

  node = codec.deserialize(codec.serialize(nullptr));
  cout << endl;
}

int main() {
  test({"1", "2", "3", "null", "null", "4", "5"});
  return 0;
}

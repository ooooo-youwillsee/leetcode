#include <iostream>
#include "Solution1.h"

TreeNode *test(vector<int> preOrder, vector<int> inOrder) {
  Solution solution;
  return solution.buildTree(preOrder, inOrder);
}

int main() {
  auto ans = test({3, 9, 20, 15, 7}, {9, 3, 15, 20, 7});
  return 0;
}

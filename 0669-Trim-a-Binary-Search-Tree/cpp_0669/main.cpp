#include <iostream>
#include "Solution1.h"

int main() {
    TreeNode *node = new TreeNode({3, 1, 4, INT_MIN, 2});
    //node->inOrder();
    Solution s;
    //node->inOrder(s.trimBST(node, 1, 2));
    node->inOrder(s.trimBST(new TreeNode({2, 1, 3}), 3, 4));
    return 0;
}
#include <iostream>
#include "Solution2.h"

void test(vector<int> vec) {
    Solution s;
    cout << s.isPalindrome(new ListNode(vec)) << endl;
}


int main() {
    test({1});
    test({1, 2});
    test({1, 0, 0});
    test({1, 0, 1});
    return 0;
}
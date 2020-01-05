#include <iostream>
#include "Solution1.h"

void test(string ss) {
    Solution s;
    cout << s.removeOuterParentheses(ss) << endl;
}

int main() {
    test("(()())(())");
    return 0;
}
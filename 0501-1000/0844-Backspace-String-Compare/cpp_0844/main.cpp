#include <iostream>
#include "Solution1.h"

void test(string s1, string s2) {
    Solution s;
    cout << s.backspaceCompare(s1, s2) << endl;
}

int main() {
    test("y#fo##f", "y#f#o##f");

    return 0;
}
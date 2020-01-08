#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string name, string typed) {
    Solution s;
    cout << s.isLongPressedName(name, typed) << endl;
}

int main() {
    test("alex", "aaleex"); // 1
    test("alex", "aaleexx");  // 1
    test("alex", "aaleexb");  // 0
    test("saeed", "ssaaedd");  // 0
    test("leelee", "lleeelee");  // 1
    test("laiden", "laiden"); // 1
    test("pyplrz","ppyypllr"); // 0
    return 0;
}
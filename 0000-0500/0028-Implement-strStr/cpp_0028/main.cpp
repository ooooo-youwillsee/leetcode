#include <iostream>
#include "Solution1.h"

void test(string s1, string s2) {
    Solution s;
    cout << s.strStr(s1, s2) << endl;
}

int main() {
    test("hello", "ll");
    test("aaaaa", "bba");
    test("", "a");
    test("ba", "a");
    test("b", "a");
    test("a", "a");
    test("a", "axxx");
    return 0;
}
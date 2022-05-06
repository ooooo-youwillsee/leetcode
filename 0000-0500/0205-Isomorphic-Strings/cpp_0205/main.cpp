#include <iostream>
#include "Solution1.h"

void test(string s, string t) {
    Solution solution;
    cout << solution.isIsomorphic(s, t) << endl;
}

int main() {
    test("", "");  //1
    test("ab", "aa"); // 0
    test("egg", "add"); //1
    test("foo", "bar");  // 0
    test("paper", "title"); //1
    return 0;
}
#include <iostream>
#include "Solution1.h"

void test(string ss) {
    Solution s;
    for (auto &c: s.reverseVowels(ss)) {
        cout << c;
    }
    cout << endl;
}

int main() {
    test("hello");
    test("leetcode");
    test("aA");
    return 0;
}
#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(string ss) {
    Solution s;
    cout << s.isPalindrome(ss) << endl;
}

int main() {
    test("A man, a plan, a canal: Panama");
    test("abc");
    test("aba");
    test("0p");
    return 0;
}
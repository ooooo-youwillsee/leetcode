#include <iostream>
#include "Solution1.h"

void test(vector<char> ss) {
    Solution s;
    s.reverseString(ss);
    for (auto &c: ss) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    test({});
    test({'a'});
    test({'h', 'e', 'l', 'l', 'o'});
    test({'H', 'a', 'n', 'n', 'a', 'h'});
    return 0;
}
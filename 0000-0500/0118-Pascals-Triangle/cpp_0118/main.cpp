#include <iostream>
#include "Solution1.h"

void test(int numRows) {
    Solution s;
    for (auto vec: s.generate(numRows)) {
        for (auto num: vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    test(5);
    return 0;
}
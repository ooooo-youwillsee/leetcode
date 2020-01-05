#include <iostream>
#include "Solution1.h"

void test(vector<int> vec) {
    Solution s;
    int res = s.removeDuplicates(vec);
    for (int i = 0; i < res; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    test({1, 1, 2});
    test({1, 2, 3});
    test({0, 0, 1, 1, 1, 2, 2, 3, 3, 4});
    return 0;
}
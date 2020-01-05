#include <iostream>
#include "Solution1.h"

void test(vector<int> vec, int val) {
    Solution s;
    int res = s.removeElement(vec, val);
    for (int i = 0; i < res; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    test({1}, 1);
    test({1}, 2);
    test({3, 2, 2, 3}, 3);
    return 0;
}
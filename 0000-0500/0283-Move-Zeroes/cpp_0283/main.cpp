#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
    Solution s;
    s.moveZeroes(nums);
    for (auto &num: nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    test({0, 1, 0, 3, 12});
    test({0});
    test({1});
    test({0, 1});
    test({1, 0});
    test({1, 0, 0});
    test({1, 0, 1});
    return 0;
}
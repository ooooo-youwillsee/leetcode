#include <iostream>
#include "Solution1.h"

void test(vector<int> nums, int k) {
    Solution s;
    cout << s.containsNearbyDuplicate(nums, k) << endl;
}

int main() {
    test({1, 2, 3, 1}, 3);
    test({1, 0, 1, 1}, 1);
    test({1, 2, 3, 1, 2, 3}, 2);
    test({99, 99}, 2);
    return 0;
}
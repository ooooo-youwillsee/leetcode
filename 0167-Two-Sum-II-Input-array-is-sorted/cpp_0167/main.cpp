#include <iostream>
#include "Solution1.h"

void test(vector<int> nums, int target) {
    Solution s;
    for (auto index :s.twoSum(nums, target)) {
        cout << index << " ";
    }
    cout << endl;
}

int main() {
    test({2, 7, 11, 15}, 9);
    return 0;
}
#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums, int target) {
    Solution s;
    cout << s.searchInsert(nums, target) << endl;
}

int main() {
    test({1, 3}, 1);
    test({1, 3}, 4);
    test({1, 3}, 2);
    return 0;
}
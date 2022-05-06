#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums1, vector<int> nums2) {
    Solution s;
    for (auto num: s.nextGreaterElement(nums1, nums2)) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    test({4, 1, 2}, {1, 3, 4, 2});
    return 0;
}
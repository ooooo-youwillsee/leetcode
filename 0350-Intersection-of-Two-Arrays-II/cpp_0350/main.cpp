#include <iostream>
#include "Solution1.h"

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution s;
    vector<int> res = s.intersect(nums1, nums2);
    for (const auto &num : res) {
        cout << num << " ";
    }
    return 0;
}
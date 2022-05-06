#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

int main() {

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    Solution s;
    s.merge(nums1, m, nums2, n);

    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
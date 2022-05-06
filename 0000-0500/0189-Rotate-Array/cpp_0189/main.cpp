#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution s;
    s.rotate(nums, 3);

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
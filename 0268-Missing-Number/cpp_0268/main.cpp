#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
    Solution s;
    cout << s.missingNumber(nums) << endl;
}

int main() {
    test({3, 0, 1});
    return 0;
}
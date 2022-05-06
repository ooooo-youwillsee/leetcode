#include <iostream>
//#include "Solution1.h"
//#include "Solution2.h"
#include "Solution3.h"
//#include "Solution4.h"

void test(vector<int> nums, int k) {
    Solution s;
    cout << s.findPairs(nums, k) << endl;
}

int main() {
    test({3, 1, 4, 1, 5}, 2);
    test({1, 2, 3, 4, 5}, 1);
    test({1, 3, 1, 5, 4}, 0);
    test({}, 0);
    test({6, 3, 5, 7, 2, 3, 3, 8, 2, 4}, 2);

    return 0;
}
#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"

void test(vector<int> nums) {
    Solution s;
    vector<int> ans = s.sortedSquares(nums);
    for (auto &num: ans) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    test({-4, -1, 0, 3, 10});
    test({-7, -3, 2, 3, 11});
    test({});
    test({-1});
    test({-1, -2});
    test({-2, -1});
    test({-2, -3});
    test({-7, -3, 2, 3, 11});
    test({-3, -3, -2, 1});
    test({-5, -4, 1, 2, 5});
    return 0;
}
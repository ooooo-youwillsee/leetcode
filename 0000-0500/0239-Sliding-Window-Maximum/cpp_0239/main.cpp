#include <iostream>
#include "Solution1.h"

using namespace std;


int main() {

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

    Solution solution;
    vector<int> res = solution.maxSlidingWindow(nums, 3);

    for (auto item : res) {
        cout << item << " ";
    }

    return 0;
}
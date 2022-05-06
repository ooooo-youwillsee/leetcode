#include <iostream>
//#include "Solution1.h"
#include "Solution2.h"
#include <vector>

using namespace std;

int main() {

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    //vector<int> nums = {0, 0, 0, 0};
    //vector<int> nums = {-2, 0, 1, 1, 2};

    Solution solution1;
    vector<vector<int>> result = solution1.threeSum(nums);
    cout << result.size() << endl;
    return 0;
}